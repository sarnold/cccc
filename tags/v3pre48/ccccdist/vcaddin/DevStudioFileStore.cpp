// DevStudioFileStore.cpp: implementation of the DevStudioFileStore class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

// Turn off warnings due to long names arising out of STL use
#pragma warning ( disable : 4786 4503 )

#include "CcccDevStudioAddIn.h"
#include "DevStudioFileStore.h"

// Use of the COM interface to the Visual Studio workspace is
// localised to this file.
#include <ObjModel\addguid.h>
#include <ObjModel\appguid.h>
#include <ObjModel\bldguid.h>
#include <ObjModel\textguid.h>
#include <ObjModel\dbgguid.h>

#include <fstream>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

// This file contains logic shamelessly copied from Joshua C. Jensen's 
// Workspace Utilities package.

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
DevStudioFileStore::DevStudioFileStore(IApplication *pApp, 
									   const std::string& wsDir, const std::string& wsName)
									   : m_pApplication(pApp)
									   , m_WorkspaceDirectory(wsDir)
									   , m_WorkspaceName(wsName)
{
	CComBSTR bszWSPath, bszWSName, bszWSFullName;
	
	VERIFY_OK(m_pApplication->get_Path(&bszWSPath));
	VERIFY_OK(m_pApplication->get_Name(&bszWSName));
	VERIFY_OK(m_pApplication->get_FullName(&bszWSFullName));
	
	VERIFY_OK(m_pApplication->PrintToOutputWindow(bszWSPath));
	VERIFY_OK(m_pApplication->PrintToOutputWindow(bszWSName));
	VERIFY_OK(m_pApplication->PrintToOutputWindow(bszWSFullName));
	
	// First, get a pointer to the dispatch for the Projects collection
	CComPtr<IDispatch> pDispProjects;
	VERIFY_OK(m_pApplication->get_Projects(&pDispProjects));
	CComQIPtr<IProjects, &IID_IProjects> pProjects(pDispProjects);
	
	// Get the number of projects in the collection
	long workspaceProjectCount;
	VERIFY_OK(pProjects->get_Count(&workspaceProjectCount));
	
	// get information on the projects
	for (long i = 1; i < workspaceProjectCount + 1; i++)
	{
		CComVariant Vari = i;
		
		// Get the next project
		CComPtr<IGenericProject> pGenProject;
		VERIFY_OK(pProjects->Item(Vari, &pGenProject));
		CComQIPtr<IGenericProject, &IID_IGenericProject> pProject(pGenProject);
		
		CComBSTR bszStr;
		VERIFY_OK(pProject->get_FullName(&bszStr));
		CString projectName = bszStr;
		
		ProjectFileStore::value_type pfsPair;
		std::string pfsName=projectName.GetBuffer(0);
		FilenameList pfsList;
		collectFilenames(pfsName,"SOURCE=",pfsList);
		m_ProjectFileStore.insert(std::make_pair(pfsName,pfsList));
	}  // end for [1..workspaceProjectCount]
	
	// dumpProjectFileList();
}

DevStudioFileStore::~DevStudioFileStore()
{
}



void DevStudioFileStore::listWorkspaceFiles(FilenameList& fileList)
{
	ProjectFileStore::const_iterator pfsIter;
	for(pfsIter=m_ProjectFileStore.begin();
	pfsIter!=m_ProjectFileStore.end();
	++pfsIter)
	{
		FilenameList::const_iterator flIter;
		for(flIter=pfsIter->second.begin();
		flIter!=pfsIter->second.end();
		++flIter)
		{
			fileList.insert(*flIter);
		}
	}
	
}

void DevStudioFileStore::listProjectFiles(std::string projectName, FilenameList& fileList)
{
	ProjectFileStore::const_iterator pfsIter;
	pfsIter=m_ProjectFileStore.find(projectName);
	std::string fileNames;
	if(pfsIter!=m_ProjectFileStore.end())
	{
		FilenameList::const_iterator flIter;
		for(flIter=pfsIter->second.begin();
		flIter!=pfsIter->second.end();
		++flIter)
		{
			fileList.insert(*flIter);
			fileNames+=*flIter+" ";
		}	
		dump(fileNames);
	}
	else
	{
		std::string msg = "Project ";
		msg.append(projectName);
		msg.append(" not found");
		AfxMessageBox(msg.c_str());
	}
}

std::string DevStudioFileStore::composeFilename(const std::string& baseDir, const std::string& relName)
{
	std::string retval;
	
	// baseDir can either be a directory specification ending in a '\' or '/'
	// or a file specification.
	// Either way
	// Now resolve relative paths.
	
	// We want to arrive at a canonical name for the file, that is a 
	// name which gives the drive letter and full path, with no use of 
	// ".."  .  We are provided with the name of the referring file 
	// and a filename (possibly) relative to that location.
	
	// Our algorithm is to compose a non-canonical name by examining
	// the potentially relative name and prepending the directory path
	// of the base location unless the relative part is seen to be
	// absolute.
	
	std::string nonCanonicalName;
	// the classes of strings which are absolute in their
	// own right are
	// 1) those which start with / or \ indicating the root directory
	//    on the current drive; and
	// 2) those which start with X: or X: indicating the root directory
	//    on the specified drive
	if( (relName[0]=='\\') || (relName[0] == '/') || (relName[1]==':') )
	{
		nonCanonicalName=relName;
	}
	else 
	{
		std::string::size_type endOfPath=baseDir.find_last_of("\\/");
		if(endOfPath!=std::string::npos)
		{
			nonCanonicalName=baseDir.substr(0,endOfPath+1)+relName;
		}
		else
		{
			// we needed a path separator and didn't find one,
			// so we are basically stuffed.
			std::string msg;
			msg.append("Couldn't compose name from ");
			msg.append(baseDir);
			msg.append(" and ");
			msg.append(relName);
			AfxMessageBox(msg.c_str());
		}
	}
	
	// Hopefully, nonCanonicalName now contains _one_ path to the 
	// file.  We use the following logic to convert this to the 
	// preferred name.
	if(nonCanonicalName.size()>0)
	{
		// The logic below has in the past contained experimentation
		// with various ways of accessing a canonical name for the 
		// file.
		// There are still two different APIs covered, anyone who knows
		// of a reason why one is better than another or why anything else
		// would be better (remember I want to support Win95/98/NT4/2000
		// in a single set of source), please mail me.
		CFileStatus fileStatus;
		CFile::GetStatus(nonCanonicalName.c_str(), fileStatus);
		
		char getFullPathNameBuf[1024],*shortNamePtr;
		unsigned long len=1024;
		memset(getFullPathNameBuf,0,len);
		int gcode=GetFullPathName(const_cast<char*>(nonCanonicalName.c_str()),
			len,getFullPathNameBuf,&shortNamePtr);
		
		
		char msgbuf[1024];
		sprintf(msgbuf,"fs=%s, "
            "GetFull returned %d name 3=%s short=%s", 
			fileStatus.m_szFullName,gcode,getFullPathNameBuf,shortNamePtr
			);
		
		// AfxMessageBox(msgbuf);
		dump(msgbuf);
		
		retval = fileStatus.m_szFullName;
	}
	
	return retval;
}

void DevStudioFileStore::collectFilenames(const std::string& dsFile, const std::string& pfx, 
										  FilenameList& fileList)
{
	std::ifstream prjStr(dsFile.c_str());
	
	const int pfxWidth=pfx.size();
	
	while(prjStr.good())
	{
		char linebuf[1024];
		prjStr.getline(linebuf,1023);
		if(!prjStr.good())
		{
			// the stream has gone bad (hopefully due to simple exhaustion)
			// no action here and the loop should terminate
		}
		else if(strncmp(linebuf,pfx.c_str(),pfxWidth)==0)
		{
			std::string relname=linebuf+pfxWidth;
			std::string absName=composeFilename(dsFile,relname);
			fileList.insert(absName);
		}
	}
}

void DevStudioFileStore::dumpProjectFileList()
{
	ProjectFileStore::const_iterator pfsIter;
	for(pfsIter=m_ProjectFileStore.begin();
	pfsIter!=m_ProjectFileStore.end();
	++pfsIter)
	{
		dump(pfsIter->first);
		dump(": ");
		
		FilenameList::const_iterator flIter;
		for(flIter=pfsIter->second.begin();
		flIter!=pfsIter->second.end();
		++flIter)
		{
			dump(flIter->c_str());
		}
		dump("");
	}
}

void DevStudioFileStore::dump(const std::string& str)
{
	VERIFY_OK(m_pApplication->PrintToOutputWindow(CComBSTR(str.c_str())));
}

std::string DevStudioFileStore::suggestedWorkingDirectory()
{
	// It would be nice to be able to make the working directory take on a constant
	// relationship to the .dsw file of the workspace, but there is no programmatic
	// way of accessing this item.
	// If we just use the current working directory of the 
	// project, we seem to start off in the .dsw file directory,
	// until a file is opened, at which point the current working
	// directory reflects the directory in which the file open
	// dialog most recently displayed.  This is not very satisfactory,
	// so for the moment we just try to use a constant directory,
	// defined either by the environment variable CCCCTEMP, with fallbacks
	// to TEMP and to the hardcoded directory c:\ (the main virtue of the latter
	// being that we are reasonably confident it will exist).
	std::string retval;
	
	char * envdir = getenv("CCCCTEMP");
	if(envdir!=0)
	{
		retval=envdir;
	}
	else
	{
		envdir=getenv("TEMP");
		if(envdir!=0)
		{
			retval=envdir;
		}
		else
		{
			retval="c:\\";
		}
	}
	return retval;
}


