// DevStudioFileStore.h: interface for the DevStudioFileStore class.
// 
// This file defines a class DevStudioFileStore which exists to encapsulate 
// the operations required to parse the .dsp and .dsw files used by 
// MS Developer studio and get the names of the files in any or all of the 
// projects in the workspace.


#if !defined(AFX_DEVSTUDIOFILESTORE_H__76B7B6C2_AA85_11D3_AFED_444553540000__INCLUDED_)
#define AFX_DEVSTUDIOFILESTORE_H__76B7B6C2_AA85_11D3_AFED_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include <string>
#include <set>
#include <map>

// The answers to queries on the class below will be 
// a collection of names.
// For the moment, I can't see why we would not want to have
// an automatically sorted list with duplicates eliminated.
typedef std::set<std::string> FilenameList;

class DevStudioFileStore  
{
public:
	DevStudioFileStore(IApplication *pApp, const std::string& wsDir, const std::string& wsName);
	virtual ~DevStudioFileStore();

	void listWorkspaceFiles(FilenameList& fileList);
	void listProjectFiles(std::string projectName, FilenameList& fileList);

	// A diagnostic function to list the files in each project
	void dumpProjectFileList();

	// a function to propose a working directory for the run.
	// If the IApplication object allowed access to the 
	// path to the .dsw file, this would be an excellent 
	// choice, but as it is there is no way of getting this,
	// so we propose either the directory containing the active
	// project (if one exists), or the directory containing
	// the active document (if one exists), or the current directory.
	std::string suggestedWorkingDirectory();

private:
	IApplication* m_pApplication;
	std::string m_WorkspaceName;
	std::string m_WorkspaceDirectory;

	typedef std::map<std::string,FilenameList> ProjectFileStore;
	ProjectFileStore m_ProjectFileStore;

	// A utility function to accept a base directory and a relative file name,
	// and translate to the canonical name of the file they specify.
	std::string composeFilename(const std::string& baseDir, const std::string& relname);

	// A utility function to open a .dsp or .dsw file, search for lines with a 
	// given prefix, and translate the remainder of those lines to filenames 
	// using the location of the opened file as the base directory.
	void collectFilenames(const std::string& dsFile, const std::string& pfx, 
		FilenameList& fileList);


	// A utility function to copy a std::string (or by implicit conversion
	// a const char*) to the Macro output tab.
	void dump(const std::string& str);
};

#endif // !defined(AFX_DEVSTUDIOFILESTORE_H__76B7B6C2_AA85_11D3_AFED_444553540000__INCLUDED_)
