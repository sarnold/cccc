// Commands.cpp : implementation file
//


#include "stdafx.h"

// Turn off warnings due to long names arising out of STL use
#pragma warning ( disable : 4786 4503 )

#include "CcccDevStudioAddIn.h"
#include "Commands.h"
#include "CommandForm.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <errno.h>

#include "DevStudioFileStore.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace 
{
	// The CCommandForm class defines a dialog
	// which basicly stores 8 editable strings 
	// which can be used as configuration data.
	// The first four are used below, we wrap them
	// with appropriate names.
	CCommandForm cmdForm;

	std::string ccccCommand()
	{
		return cmdForm.cmdText(0).GetBuffer(0);
	}

	std::string browserCommand()
	{
		return cmdForm.cmdText(1).GetBuffer(0);
	}

	// the user commands are stored after the 
	// strings reserved for use in the CCCC commands
	std::string userCommand(int whichOne)
	{
		// the user commands are indexed from one, so
		// we find the one we want by adding the index
		// to the index of the last space in the command
		// configuration form reserved for use by the add-in
		return cmdForm.cmdText(1+whichOne);
	}

}

/////////////////////////////////////////////////////////////////////////////
// CCommands

CCommands::CCommands()
{
	m_pApplication = NULL;
}

CCommands::~CCommands()
{
	ASSERT (m_pApplication != NULL);
	m_pApplication->Release();
}

void CCommands::SetApplicationObject(IApplication* pApplication)
{
	// This function assumes pApplication has already been AddRef'd
	//  for us, which CDSAddIn did in its QueryInterface call
	//  just before it called us.
	m_pApplication = pApplication;
}


/////////////////////////////////////////////////////////////////////////////
// CCommands methods

STDMETHODIMP CCommands::CcccDevStudioAddInCommandMethod() 
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Replace this with the actual code to execute this command
	//  Use m_pApplication to access the Developer Studio Application object,
	//  and VERIFY_OK to see error strings in DEBUG builds of your add-in
	//  (see stdafx.h)

	VERIFY_OK(m_pApplication->EnableModeless(VARIANT_FALSE));
	AfxMessageBox(_T("CcccDevStudioAddIn Command invoked."), 
		MB_OK | MB_ICONINFORMATION);
	VERIFY_OK(m_pApplication->EnableModeless(VARIANT_TRUE));
	return S_OK;
}

STDMETHODIMP CCommands::configureCCCCDevStudioAddIn()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	cmdForm.DoModal();
	return S_OK;
}


STDMETHODIMP CCommands::runCCCCOnActiveFile()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here

	CComPtr<IDispatch> pDoc;
	VERIFY_OK(m_pApplication->get_ActiveDocument(&pDoc));
	CComQIPtr<IGenericDocument, &IID_IGenericDocument> p_Document(pDoc);
	
	CComBSTR bszStr;
	VERIFY_OK(p_Document->get_FullName(&bszStr));
	CString fileName = bszStr;

	FilenameList files;
	files.insert(static_cast<const char*>(fileName));
	runCCCC(files);
	return S_OK;
}


STDMETHODIMP CCommands::runCCCCOnProjectFiles()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	FilenameList files;
	DevStudioFileStore dsfs(m_pApplication,"","");

	// get the name of the active project from the workspace
	CComPtr<IDispatch> p_ActiveProject;
	VERIFY_OK(m_pApplication->get_ActiveProject(&p_ActiveProject));
	CComQIPtr<IGenericProject, &IID_IGenericProject> p_Project(p_ActiveProject);
	
	CComBSTR bszStr;
	VERIFY_OK(p_Project->get_FullName(&bszStr));
	CString projectName = bszStr;

	dsfs.listProjectFiles(static_cast<LPCSTR>(projectName),files);
	runCCCC(files);

	return S_OK;
}

STDMETHODIMP CCommands::runCCCCOnWorkspaceFiles()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	FilenameList workspaceFiles;
	DevStudioFileStore dsfs(m_pApplication,"","");
	dsfs.listWorkspaceFiles(workspaceFiles);
	runCCCC(workspaceFiles);

	return S_OK;
}

STDMETHODIMP CCommands::configureAddIn()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	runProcess("c:\\COMMAND /c dir");

	return S_OK;
}

void CCommands::runProcess(const std::string& commandLine)
{
    STARTUPINFO si;    
	PROCESS_INFORMATION pi;    
	ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);    // Start the child process. 
    if( !CreateProcess( NULL, // No module name (use command line). 
        const_cast<char*>(commandLine.c_str()), // Command line. 
        NULL,             // Process handle not inheritable. 
        NULL,             // Thread handle not inheritable. 
        FALSE,            // Set handle inheritance to FALSE. 
        0,                // No creation flags. 
        NULL,             // Use parent’s environment block. 
        NULL,             // Use parent’s starting directory. 
        &si,              // Pointer to STARTUPINFO structure.
        &pi )             // Pointer to PROCESS_INFORMATION structure.    ) 
	)
    {
		AfxMessageBox("CreateProcess failed.");
	}
	else
	{
		// Wait until child process exits.
		WaitForSingleObject( pi.hProcess, INFINITE );
	}
    // Close process and thread handles.     CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );	
	/*
	char   lineBuffer[1024];
	FILE   *procOutput;

	std::string outFile=tmpnam(NULL);
	std::string fullCommand=commandLine+">"+outFile;

	int cmdStatus=system(fullCommand.c_str());

	if(cmdStatus==0)
	{
		procOutput = fopen( outFile.c_str(), "rt");
		if(procOutput!=NULL)
		{
			while( !feof( procOutput ) )
			{
				if( fgets( lineBuffer, 1023, procOutput ) != NULL )
				{
					VERIFY_OK(m_pApplication->PrintToOutputWindow(CComBSTR(lineBuffer)));
				}
			}
		}
		else
		{
			std::string msg;
			msg.append("Failed to open ");
			msg.append(outFile);
			VERIFY_OK(m_pApplication->PrintToOutputWindow(CComBSTR(msg.c_str())));
		}
	}
	// else
	{
		CComBSTR bstrError;
		CComPtr<IErrorInfo> pErrorInfo;
		if (GetErrorInfo(0, &pErrorInfo) == S_OK)
		{
			pErrorInfo->GetDescription(&bstrError);
		}
		VERIFY_OK(m_pApplication->PrintToOutputWindow(CComBSTR(fullCommand.c_str())));
		std::string msg;
		msg.append("Command result: ");
		msg.append(strerror(errno));
		VERIFY_OK(m_pApplication->PrintToOutputWindow(CComBSTR(msg.c_str())));
		VERIFY_OK(m_pApplication->PrintToOutputWindow(bstrError));
	}
	// get rid of the temporary file
	unlink(outFile.c_str());
*/
}

void CCommands::runCCCC(const FilenameList& fileList)
{
	// The Win95 command.com can only accept a command line of up
	// to about 128 characters, so we use the option on CCCC to load the filenames from
	// a file

	DevStudioFileStore dsfs(m_pApplication,"","");
	std::string ccccBaseDir=dsfs.suggestedWorkingDirectory();
	ccccBaseDir.append("\\.cccc");

	std::string ccccCommandLine=ccccCommand();
	ccccCommandLine.append(" --outdir=");
	ccccCommandLine.append(ccccBaseDir);
	FilenameList::const_iterator flIter;
	for(flIter=fileList.begin();
	flIter!=fileList.end();
	++flIter)
	{
		ccccCommandLine.append(" ");
		ccccCommandLine.append(*flIter);
	}
	runProcess(ccccCommandLine);

	std::string browseCommandLine;
	browseCommandLine=browserCommand();
	browseCommandLine.append(" ");

	browseCommandLine.append(ccccBaseDir);
	browseCommandLine.append("\\cccc.html");
	runProcess(browseCommandLine);
}

STDMETHODIMP CCommands::userCommand1()
{
	runProcess(userCommand(1));
	return S_OK;
}

STDMETHODIMP CCommands::userCommand2()
{
	runProcess(userCommand(2));
	return S_OK;
}

STDMETHODIMP CCommands::userCommand3()
{
	runProcess(userCommand(3));
	return S_OK;
}

STDMETHODIMP CCommands::userCommand4()
{
	runProcess(userCommand(4));
	return S_OK;
}

STDMETHODIMP CCommands::userCommand5()
{
	runProcess(userCommand(5));
	return S_OK;
}

STDMETHODIMP CCommands::userCommand6()
{
	runProcess(userCommand(6));
	return S_OK;
}
