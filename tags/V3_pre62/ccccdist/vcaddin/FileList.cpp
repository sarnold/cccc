#include "stdafx.h"
#include "FileList.h"

FileList::FileList()
:	m_fileList(100)
{
}


FileList::~FileList()
{
}


File& FileList::Add(const File& file)
{
	POSITION pos = m_fileList.AddTail((File&)file);
	return m_fileList.GetAt(pos);
}

	
void FileList::RemoveAll()
{
	m_fileList.RemoveAll();
	m_fileArray.RemoveAll();
}


void FileList::BuildArray()
{
	// Build the file array.
	m_fileArray.RemoveAll();
	m_fileArray.SetSize(m_fileList.GetCount());

	int arrayPos = 0;
	POSITION listPos = m_fileList.GetHeadPosition();
	while (listPos != NULL)
	{
		Info info;
		info.m_pos = listPos;
		info.m_file = &m_fileList.GetNext(listPos);
		m_fileArray[arrayPos++] = info;
	}
}

	
static int __cdecl CompareArray(const void* elem1, const void* elem2)
{
	FileList::Info* info1 = (FileList::Info*)elem1;
	FileList::Info* info2 = (FileList::Info*)elem2;
	File* file1 = info1->m_file;
	File* file2 = info2->m_file;

	int ret = file1->GetShortName().Compare(file2->GetShortName());
	if (ret == 0)
	{
		// If the names match, compare against the file extensions.
		ret = file1->GetExt().Compare(file2->GetExt());
		if (ret == 0)
		{
			// If the extensions match, compare against the path.
			ret = file1->GetPath().CompareNoCase(file2->GetPath());
			if (ret == 0)
			{
				file1->SetDuplicate(true);
				file2->SetDuplicate(true);
			}
		}
	}
	return ret;
}
	

void FileList::Sort()
{
	// Build the file array.
	BuildArray();
	
	// Sort the file array.
	qsort(m_fileArray.GetData(), m_fileArray.GetSize(), sizeof(Info), CompareArray);

	// Remove duplicates.
	for (int curPos = 0; curPos < m_fileArray.GetSize(); curPos++)
	{
		File& file = *m_fileArray[curPos].m_file;

		// Check for duplicates.
		if (!file.m_duplicate)
			continue;

		// Found a duplicate... see how many more match.
		for (int endPos = curPos + 1; endPos < m_fileArray.GetSize(); endPos++)
		{
			File& fileCmp = *m_fileArray[endPos].m_file;
			int ret = file.GetShortName().Compare(fileCmp.GetShortName());
			if (ret)
				break;

			// If the names match, compare against the file extensions.
			ret = file.GetExt().Compare(fileCmp.GetExt());
			if (ret)
				break;

			// If the extensions match, compare against the path.
			ret = file.GetPath().CompareNoCase(fileCmp.GetPath());
			if (ret)
				break;
		}

		// [endPos] is now the last one that matched.
		if (endPos - curPos < 2)
		{
			// Huh?
			continue;
		}

		// Remove them.
		for (int i = curPos + 1; i < endPos; i++)
		{
			m_fileList.RemoveAt(m_fileArray[i].m_pos);
		}

		m_fileArray.RemoveAt(curPos + 1, endPos - curPos - 1);
	}
}

// Find exact file index.
int FileList::FindExact(File& file) const
{
	// Scan the file list.
	for (int i = 0; i < GetCount(); i++)
	{
		File& fileCmp = (*this)[i];

		// Compare the extension.
		if (!file.GetExt().IsEmpty()  &&  file.GetExt() != fileCmp.GetExt())
			continue;

		// Compare the short name.
		if (file.GetShortName() != fileCmp.GetShortName())
			continue;

		// Compare the path.
		if (file.GetPath().CompareNoCase(fileCmp.GetPath()) == 0)
		{
			return i;
		}
	}

	return -1;
}


// Find next file index.
int FileList::FindNext(int startPos, File& file) const
{
	// Scan the file list.
	for (int i = startPos + 1; i < GetCount(); i++)
	{
		File& fileCmp = (*this)[i];

		// Compare the short name.
		if (file.GetShortName() == fileCmp.GetShortName())
			return i;
	}

	for (i = 0; i < startPos; i++)
	{
		File& fileCmp = (*this)[i];

		// Compare the short name.
		if (file.GetShortName() == fileCmp.GetShortName())
			return i;
	}

	return -1;
}


// Find next file index.
int FileList::FindPrevious(int startPos, File& file) const
{
	// Scan the file list.
	for (int i = startPos - 1; i >= 0; i--)
	{
		File& fileCmp = (*this)[i];

		// Compare the short name.
		if (file.GetShortName() == fileCmp.GetShortName())
			return i;
	}

	for (i = GetCount() - 1; i > startPos; i--)
	{
		File& fileCmp = (*this)[i];

		// Compare the short name.
		if (file.GetShortName() == fileCmp.GetShortName())
			return i;
	}

	return -1;
}


