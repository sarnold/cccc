#ifndef FILELIST_H
#define FILELIST_H

#include <afxtempl.h>

///
class File
{
	friend class FileList;
public:
	File();

	static bool Create(File& file, const CString& rootPath, CString filename, bool resolve = true);

	void* GetParent(void) const;
	const CString& GetShortName(void) const;
	const CString& GetTitle(void) const;
	const CString& GetExt(void) const;
	const CString& GetPath(void) const;

	void SetParent(void* parent);
	void SetShortName(const CString& shortName);
	void SetTitle(const CString& title);
	void SetExt(const CString& ext);
	void SetPath(const CString& path);
	void SetDuplicate(bool duplicate);

protected:
	void* m_parent;

	CString m_shortName;
	CString m_title;
	CString m_ext;
	CString m_path;

	bool m_duplicate;
}; //File


class FileList
{
public:
	FileList();
	~FileList();

// Attributes
	int GetCount(void) const;

// Operations	
	File& Add(const File& file);
	void RemoveAll(void);
	void Sort(void);
	File& operator[](int index) const;

	int FindExact(File& file) const;
	int FindNext(int startPos, File& file) const;
	int FindPrevious(int startPos, File& file) const;

	struct Info
	{
		POSITION m_pos;
		File* m_file;
	};

protected:
	void BuildArray(void);

	CList<File, File&> m_fileList;
	CArray<Info, Info&> m_fileArray;
};

inline File::File()
:	m_duplicate(false)
{ }
inline void* File::GetParent(void) const
{  return m_parent;  }
inline const CString& File::GetShortName(void) const
{  return m_shortName;  }
inline const CString& File::GetTitle(void) const
{  return m_title;  }
inline const CString& File::GetExt(void) const
{  return m_ext;  }
inline const CString& File::GetPath(void) const
{  return m_path;  }
inline void File::SetParent(void* parent)
{  m_parent = parent;  }
inline void File::SetShortName(const CString& shortName)
{  m_shortName = shortName;  }
inline void File::SetTitle(const CString& title)
{  m_title = title;  }
inline void File::SetExt(const CString& ext)
{  m_ext = ext;  }
inline void File::SetPath(const CString& path)
{  m_path = path;  }
inline void File::SetDuplicate(bool duplicate)
{  m_duplicate = duplicate;  }

inline int FileList::GetCount(void) const
{  return m_fileList.GetCount();  }
inline File& FileList::operator[](int index) const
{  return *m_fileArray[index].m_file;  }

#endif FILELIST_H