#include "stdafx.h"
//#include <initguid.h>
#include "CcccDevStudioAddIn.h"
#include "DSAddIn.h"
#include "Commands.h"
#include "afx.h"
#include "WorkspaceInfo.h"


IApplication* WorkspaceInfo::m_pApplication;
CString WorkspaceInfo::m_workspaceLocation;
CString WorkspaceInfo::m_extraFilename;
CString WorkspaceInfo::m_excludeFilename;

WorkspaceInfo::ProjectList WorkspaceInfo::m_projects;
FileList WorkspaceInfo::m_fileList;

// Resolves the filename when it contains environment variables and relative paths.
void ResolveFilename(const CString& rootDir, CString& filename)
{
/*
	// Initially resolve all environment variables.
	int position = -1;
	while (1)
	{
		// Search for $ symbols, denoting an environment variable.
		position = filename.Find('$', position + 1);
		if (position == -1)
			break;

		// Okay, there is an environment variable in there... resolve it.
		if (filename[position + 1] == '(')
		{
			int lastpos = filename.Find(')');
			CString env = filename.Mid(position + 2, lastpos - (position + 2));

			// See if we can resolve it.  If not, then exit.
			char buffer[_MAX_PATH];
			if (GetEnvironmentVariable(env, buffer, _MAX_PATH) == 0)
				continue;

			// Okay, rebuild the string.
			filename = filename.Left(position) + buffer +
						filename.Right(filename.GetLength() - lastpos - 1);
		}
	}

	// Now resolve relative paths.
	CFileStatus fileStatus;
	if (filename[0] == '.')
		filename = rootDir + filename;
	CFile::GetStatus(filename, fileStatus);
	filename = fileStatus.m_szFullName;
*/
}


//
bool File::Create(File& file, const CString& rootPath, CString filename, bool resolve)
{
	// Resolve the filename.
	if (resolve)
		ResolveFilename(rootPath, filename);

	// Find the path.
	int pathEndPosition = filename.ReverseFind('\\');
	if (pathEndPosition == -1)
		return false;
	file.SetPath(filename.Left(pathEndPosition + 1));

	// Find the extension.
	int extPosition = filename.ReverseFind('.');
	if (extPosition != -1)
	{
		file.m_ext = filename.Mid(extPosition + 1);
		file.m_ext.MakeLower();
	}
	else
		extPosition = filename.GetLength();

	// Find the file title.
	file.m_title = filename.Mid(pathEndPosition + 1, extPosition - (pathEndPosition + 1));

	// Build the shortened name (no symbols).
	char shortName[200];
	int sLen = 0;
	for (int i = 0; i < file.m_title.GetLength(); i++)
		if (isalnum(file.m_title[i]))
			shortName[sLen++] = tolower(file.m_title[i]);
	shortName[sLen] = 0;
	file.m_shortName = shortName;

	// Set the parent.
	file.m_parent = NULL;

	return true;
}


// This is a cheap way to get the workspace location, but it is the only way
// which consistently worked.  DevStudio, failing once again, provides no function to
// return the location of the workspace.
void WorkspaceInfo::SetWorkspaceLocation(void)
{
	// Call the OS for the current directory.
	LPTSTR str = m_workspaceLocation.GetBuffer(_MAX_PATH);
	::GetCurrentDirectory(_MAX_PATH, str);
	m_workspaceLocation.ReleaseBuffer();

	// Make sure it ends in a closing backslash.
	if (m_workspaceLocation[m_workspaceLocation.GetLength() - 1] != '\\')
	{
		m_workspaceLocation += "\\";
	}

	m_extraFilename = m_workspaceLocation + "ExtraFiles.WU";
	m_excludeFilename = m_workspaceLocation + "ExcludeFiles.WU";
}


// See if the .dsp or .dsw file changed on disk.
bool WorkspaceInfo::CheckProjectIntegrity(CString projectName)
{
	// Resolve the filename.
	ResolveFilename(GetWorkspaceLocation(), projectName);

	// Scan the projects list to find the project named [projectName].
	POSITION pos = m_projects.GetHeadPosition();
	Project* prj = NULL;
	while (pos != NULL)
	{
		prj = &m_projects.GetNext(pos);
		if (prj->m_name.CompareNoCase(projectName) == 0)
			break;
		prj = NULL;
	}

	// If it doesn't exist, exit.
	if (!prj)
	{
//			AfxMessageBox("Refresh: Project names differ.");
		return false;
	}

	// Check the date and time stamp.
	CFileStatus fileStatus;
	if (CFile::GetStatus(prj->m_name, fileStatus) == FALSE)
		return false;
	if (prj->m_timeStamp != fileStatus.m_mtime)
	{
//			AfxMessageBox("Refresh:  Date/time stamp differs.");
		return false;
	}

	return true;
}


// CheckIntegrity() returns false if the internally stored projects 
// don't match the Visual Studio projects.
bool WorkspaceInfo::CheckIntegrity(void)
{
	// If there are no projects to compare against, then fail the integrity check.
	if (m_projects.GetCount() == 0)
	{
//		AfxMessageBox("Refresh: No projects.");
		return false;
	}

	// Is there an add-on file?
	int numAddOnProjects = 0;
	CStdioFile file;
	if (file.Open(GetExtraFilename(), CFile::modeRead) == TRUE)
	{
		CString line;
		
		// Count the number of extra projects.
		while (1)
		{
			// Read in a project name.
			if (!file.ReadString(line))
				break;

			// Check the integrity.
			if (!CheckProjectIntegrity(line))
				return false;

			// Increment the number of add-on projects.
			numAddOnProjects++;
		} 

		// Close the file.
		file.Close();
	}

	// Now run all projects with workspace parents (which means they were added
	// indirectly through a .dsw file).
	POSITION pos = m_projects.GetHeadPosition();
	while (pos != NULL)
	{
		// Get the project.
		Project& prj = m_projects.GetNext(pos);

		// Does it have a parent?
		if (prj.m_parent)
		{
			// Yes, so it is a project added indirectly from a .dsw file.
			if (!CheckProjectIntegrity(prj.GetName()))
				return false;

			// Add it to the number of add-on projects.
			numAddOnProjects++;
		}
	}
	
	// First, get a pointer to the dispatch for the Projects collection
	CComPtr<IDispatch> pDispProjects;
	VERIFY_OK(m_pApplication->get_Projects(&pDispProjects));
	CComQIPtr<IProjects, &IID_IProjects> pProjects(pDispProjects);

	// Get the number of projects in the collection
	long workspaceProjectCount;
	VERIFY_OK(pProjects->get_Count(&workspaceProjectCount));

	// If the number of projects reported by Visual Studio is not the same
	//   number as our local project list, then refresh everything.
	if (workspaceProjectCount + numAddOnProjects != m_projects.GetCount())
	{
//		AfxMessageBox("Refresh: Project counts differ.");
		return false;
	}

	// Check for non-matching project names.
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

		// Check the project integrity.
		if (!CheckProjectIntegrity(projectName))
			return false;
	}  // end for [1..workspaceProjectCount]

	return true;
}


// Clean the projects and filenames lists.
void WorkspaceInfo::RemoveAll(void)
{
	// Clean the projects list.
	m_projects.RemoveAll();

	// Clean the filenames list.
	m_fileList.RemoveAll();
}


// Since Visual Studio provides no COM method of returning the names of
// files in a project, we have to cheat, and read them from the .DSP
// files on disk.  This has at least one primary disadvantage.  If a
// change is made to the project in the Developer Studio, the project
// MUST be saved before we can process the change here.
void WorkspaceInfo::ReadDSPFile(Project& prj)
{
	// Open the .dsp file.
	CStdioFile file;
	if (file.Open(prj.GetName(), CFile::modeRead) == FALSE)
	{
		// Huh?
		return;
	}

	// Build the root path to resolve filenames from.
	CString rootPath = prj.m_name.Left(prj.m_name.ReverseFind('\\') + 1);

	// Begin reading the file.
	CString line;
	while (1)
	{
		// Read in a line from the file.
		if (!file.ReadString(line))
			break;

		// Check for SOURCE= lines.  (Do strncmp() for speed)
		if (line.GetLength() <= 7  ||  strncmp(line, "SOURCE=", 7) != 0)
			continue;

		///////////////////////////////////////////////////////////////////////
		// Start the pointer just after the SOURCE=, but strip the beginning
		// and end quotes if they exist.
		int startPos;
		if (line[7] == '"')
			startPos = 8;
		else
			startPos = 7;

		int endPos;
		if (line[line.GetLength() - 1] == '"')
			endPos = line.GetLength() - 1;
		else
			endPos = line.GetLength();

		// Create and resolve the filename.
		CString filename = line.Mid(startPos, endPos - startPos);

		// Create the file structure.
		File file;
		if (File::Create(file, rootPath, filename) == false)
			continue;
		
		// Set the parent.
		file.SetParent(&prj);

		// Insert it.
		m_fileList.Add(file);

	} //while(1)

	// Close the .dsp file.
	file.Close();
}


// Read in a .dsw file.
void WorkspaceInfo::ReadDSWFile(Project& prj)
{
	// Open the .dsw file.
	CStdioFile file;
	if (file.Open(prj.m_name, CFile::modeRead) == FALSE)
	{
		// Huh?
		return;
	}

	// Build the root path to resolve filenames from.
	CString rootPath = prj.m_name.Left(prj.m_name.ReverseFind('\\') + 1);

	// Begin reading the file.
	CString line;
	while (1)
	{
		// Read in a line from the file.
		if (!file.ReadString(line))
			break;

		// Look for something that looks like this.
		// Project: "!EagleLib"=".\Prj\!EagleLib.dsp" - Package Owner=<4>
		// Project: "Gfx"=.\Prj\Gfx.dsp - Package Owner=<4>
		if (line.GetLength() <= 8  ||  strncmp(line, "Project:", 8) != 0)
			continue;

		// Search for the =.
		int endPos;		// Will be one past the last letter.
		int startPos = line.Find('=');
		if (startPos == -1)
			continue;
		startPos++;		// Move to the beginning of the name.

/*
		// See if the name is quoted.
		if (line[startPos] == '"')
		{
			// Move past the quote.
			startPos++;
			
			// Find the closing quote.
			endPos = line.Find('"', startPos);
			if (endPos == -1)
				continue;
		}
		else //if (line[namePos] == '"')
		{
			// Find a space, since that should denote the end of the filename.
			endPos = line.Find(' ', startPos);
		}
*/

		// Got the name isolated.  Add it.
		CString projectPath = line.Mid(startPos, endPos - startPos);
		ResolveFilename(rootPath, projectPath);
		Project* newlyAddedProject = AddHelper(projectPath);
		if (newlyAddedProject)
			newlyAddedProject->m_parent = &prj;
	} //while(1)
	// Close the .dsp file.
	file.Close();
}


// Add a new project or workspace to the list of projects.
void WorkspaceInfo::Add(CString projectName)
{
	AddHelper(projectName);
}


// Internal helper function.
WorkspaceInfo::Project* WorkspaceInfo::AddHelper(CString projectName)
{
	// Resolve the filename.
	ResolveFilename(GetWorkspaceLocation(), projectName);
	
	// Make sure there is an extension.
	int dotPosition = projectName.ReverseFind('.');
	if (dotPosition == -1)
	{
		// What?!
		return NULL;
	}

	// Make sure the file exists.
	CFileStatus fileStatus;
	if (CFile::GetStatus(projectName, fileStatus) == FALSE)
		return NULL;

	// Create the project structure.
	Project prjToAdd;
	prjToAdd.m_name = projectName;
	prjToAdd.m_active = true;
	prjToAdd.m_timeStamp = fileStatus.m_mtime;
	prjToAdd.m_parent = NULL;

	// This is a little slow, but it can be moved later.
	CStdioFile file;
	if (file.Open(GetExcludeFilename(), CFile::modeRead) == TRUE)
	{
		CString line;
		
		// Count the number of extra projects.
		while (1)
		{
			// Read in a project name.
			if (!file.ReadString(line))
				break;

			// Resolve the exclude filename.
			ResolveFilename(GetWorkspaceLocation(), line);

			// If it matches, then the project is inactive.
			if (prjToAdd.m_name.CompareNoCase(line) == 0)
			{
				prjToAdd.m_active = false;
				break;
			}
		} 

		// Close the file.
		file.Close();
	}

	// Add it to the end of the projects list.
	POSITION pos = m_projects.AddTail(prjToAdd);
	Project& prj = WorkspaceInfo::m_projects.GetAt(pos);
		
	// If the project is inactive, leave.
	if (!prj.IsActive())
	{
		return &prj;
	}

	// Determine which type of file this is:
	CString ext = prj.m_name.Mid(dotPosition + 1);
	ext.MakeLower();
	if (ext == "dsw")
	{
		// This is a workspace file.
		ReadDSWFile(prj);
	}
	else if (ext == "dsp")
	{
		// Assume it is a project file.
		ReadDSPFile(prj);
	}
	else
	{
		// Fail
	}

	return &prj;
}

// Refresh the projects list.
bool WorkspaceInfo::Refresh(void)
{
	// If the internal project integrity is good, then no refresh is needed.
	if (CheckIntegrity())
		return true;

	// Delete everything.
	RemoveAll();

	// First, get a pointer to the dispatch for the Projects collection
	CComPtr<IDispatch> pDispProjects;
	VERIFY_OK(m_pApplication->get_Projects(&pDispProjects));
	CComQIPtr<IProjects, &IID_IProjects> pProjects(pDispProjects);

	// Get the number of projects in the collection
	long projectCount;
	VERIFY_OK(pProjects->get_Count(&projectCount));

	// Iterate all the projects.
	for (long i = 1; i < projectCount + 1; i++)
	{
		CComVariant Vari = i;

		// Get the next project
		CComPtr<IGenericProject> pGenProject;
		VERIFY_OK(pProjects->Item(Vari, &pGenProject));
		CComQIPtr<IGenericProject, &IID_IGenericProject> pProject(pGenProject);

		// Get the project name.
		CComBSTR bszStr;
		VERIFY_OK(pProject->get_FullName(&bszStr));
		CString projectName = bszStr;

		Add(projectName);
	}

	// Rename a misnamed add-on file.
	CString oldFilename = m_workspaceLocation + "ExtraFiles.PFO";
	CString wuFilename = GetExtraFilename();
	rename(oldFilename, wuFilename);

	// Is there an add-on file?
	CStdioFile file;
	if (file.Open(wuFilename, CFile::modeRead) == TRUE)
	{
		CString line;
		
		// Count the number of extra projects.
		while (1)
		{
			// Read in a project name.
			if (!file.ReadString(line))
				break;

			// Check the integrity.
			Add(line);
		} 

		// Close the file.
		file.Close();
	}

	// Build the file array.
	m_fileList.Sort();

	// Rebuilt stuff.
	return false;
}

