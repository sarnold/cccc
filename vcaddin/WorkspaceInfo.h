#ifndef WORKSPACEINFO_H
#define WORKSPACEINFO_H

#include "resource.h"		// main symbols

#include <ObjModel\addguid.h>
#include <ObjModel\appguid.h>
#include <ObjModel\bldguid.h>
#include <ObjModel\textguid.h>
#include <ObjModel\dbgguid.h>

#include "FileList.h"

///
class WorkspaceInfo
{
public:
	///
	class Project
	{
		friend class WorkspaceInfo;
	public:
		const CString& GetName(void) const;
		bool IsActive(void) const;
		const CTime& GetTimeStamp(void) const;

		void SetActive(bool active);
	
	protected:
		CString m_name;			// The name of the project or workspace.
		bool m_active;			// Is the project active?
		CTime m_timeStamp;		// The time stamp of the project.
		Project* m_parent;		// Parent project.
	}; //Project

	typedef CList<Project, Project&> ProjectList;

public:
// Attributes
	static ProjectList& GetProjectList(void);	// Not const on purpose.
	static FileList& GetFileList(void);			// Not const on purpose.
	static const CString& GetWorkspaceLocation(void);
	static const CString& GetExtraFilename(void);
	static const CString& GetExcludeFilename(void);

// Operations
	static void SetWorkspaceLocation(void);		// Do once on Workspace Open.
	static bool CheckIntegrity(void);
	static bool Refresh(void);
	static void Add(CString projectName);
	static void RemoveAll(void);

	static IApplication *m_pApplication;

protected:
	static bool CheckProjectIntegrity(CString projectName);
	static void ReadDSPFile(Project& prj);
	static void ReadDSWFile(Project& prj);
	static Project* AddHelper(CString projectName);

	static CString m_workspaceLocation;
	static CString m_extraFilename;
	static CString m_excludeFilename;

	static ProjectList m_projects;
	static FileList m_fileList;
}; //WorkspaceInfo


inline const CString& WorkspaceInfo::Project::GetName(void) const
{  return m_name;  }
inline bool WorkspaceInfo::Project::IsActive(void) const
{  return m_active;  }
inline const CTime& WorkspaceInfo::Project::GetTimeStamp(void) const
{  return m_timeStamp;  }
inline void WorkspaceInfo::Project::SetActive(bool active)
{  m_active = active;  }


inline WorkspaceInfo::ProjectList& WorkspaceInfo::GetProjectList(void)
{  return m_projects;  }
inline FileList& WorkspaceInfo::GetFileList(void)
{  return m_fileList;  }
inline const CString& WorkspaceInfo::GetWorkspaceLocation(void)
{  return m_workspaceLocation;  }
inline const CString& WorkspaceInfo::GetExtraFilename(void)
{  return m_extraFilename;  }
inline const CString& WorkspaceInfo::GetExcludeFilename(void)
{  return m_excludeFilename;  }

#endif WORKSPACEINFO_H

