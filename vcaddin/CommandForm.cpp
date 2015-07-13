// CommandForm.cpp : implementation file
//


#include "stdafx.h"

// Turn off warnings due to long names arising out of STL use
#pragma warning ( disable : 4786 4503 )

#include "CcccDevStudioAddIn.h"
#include "CommandForm.h"

#include <list>
#include <string>
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace
{
	// This namespace encapsulates a function to search for 
	// a particular file in a list of directories.
	// Parameter fileName is initialized with the unqualified name
	// of the file which is sought, while path contains a list of 
	// strings for the directories where the file might be.
	typedef std::list<std::string> PathList;

	bool findFileOnPath(std::string& fileName, const PathList& path)
	{
		bool retval=false;
		PathList::const_iterator plIter=path.begin();
		while( (retval==false) && (plIter!=path.end()) )
		{
			std::string testName=*plIter+fileName;
			std::ifstream testStr(testName.c_str());
			if(testStr.good())
			{
				retval=true;
				fileName="\""+testName+"\"";

			}
			plIter++;
		}
		return retval;
	} // end of findFileOnPath()
} // end of anonymous namespace

// The standard for registry paths appears to be Software/<vendor>/<package>
// hence the fact that I am putting my name in your registry.
// It's not just vanity, honest.
HKEY registryTopLevelKey=HKEY_CURRENT_USER;
const char* registryKeyPath="Software\\TimLittlefair\\CcccDevStudioAddIn";
const char* registryValueName="STRINGS";

const int BUF_SIZE=10240;

/////////////////////////////////////////////////////////////////////////////
// CCommandForm dialog


CCommandForm::CCommandForm(CWnd* pParent /*=NULL*/)
	: CDialog(CCommandForm::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCommandForm)
	//}}AFX_DATA_INIT

	loadConfiguration();
}

CCommandForm::~CCommandForm()
{
	saveConfiguration();
}

void CCommandForm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommandForm)
	//}}AFX_DATA_MAP

	DDX_Text(pDX, IDC_EDIT1, m_Cmd[0]);
	DDX_Text(pDX, IDC_EDIT2, m_Cmd[1]);
	DDX_Text(pDX, IDC_EDIT3, m_Cmd[2]);
	DDX_Text(pDX, IDC_EDIT4, m_Cmd[3]);
	DDX_Text(pDX, IDC_EDIT5, m_Cmd[4]);
	DDX_Text(pDX, IDC_EDIT6, m_Cmd[5]);
	DDX_Text(pDX, IDC_EDIT7, m_Cmd[6]);
	DDX_Text(pDX, IDC_EDIT8, m_Cmd[7]);

	// save the modified information in the registry
	saveConfiguration();
}


BEGIN_MESSAGE_MAP(CCommandForm, CDialog)
	//{{AFX_MSG_MAP(CCommandForm)
	ON_BN_CLICKED(IDC_BUTTON1, OnDefaults)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommandForm message handlers

void CCommandForm::setDefaults()
{
	// This function is virtual so that it could
	// be overridden for a specific application

	// For the moment I am hard-coding the strings required
	// for my CCCC AddIn app here, but it would be better to 
	// inherit and override.

	// The next string is used in the message displayed at the end of
	// this function.
	std::string missingFiles;

	// The command to run CCCC.
	std::string ccccName="cccc.exe";
	PathList ccccSearchPath;
	ccccSearchPath.push_back("C:\\Program Files\\CCCC\\");
	if( findFileOnPath(ccccName,ccccSearchPath) )
	{
		m_Cmd[0]=ccccName.c_str();
	}
	else
	{
		m_Cmd[0]="echo No location configured for CCCC.EXE";
		missingFiles="the program CCCC.EXE";
	}

	// We also need to know the location of a browser.
	// The default is to search a couple of likely locations for
	// a copy of Internet Explorer.  This is very much the lowest common
	// denominator because I know it is more likely to be present than
	// not.  The CCCC report should be equally easy to read with a version
	// of Netscape/Mozilla, Opera, or any other graphical browser (lynx won't
	// work too well, I'm afraid).
	// I would welcome advice on other locations IE might be in: the two below
	// reflect my Win95 OSR2 box at home and WinNT 4.0 at work, so I assume that
	// Win98, Win98SE and Win2000 may need still different locations.
	// If you find one of these, please mail me on tim_littlefair@hotmail.com.
	std::string browserName="iexplore.exe";
	PathList browserSearchPath;
	browserSearchPath.push_back("C:\\Program Files\\Plus!\\Microsoft Internet\\");
	browserSearchPath.push_back("C:\\Program Files\\Internet Explorer\\");
	if( findFileOnPath(browserName,browserSearchPath) )
	{
		m_Cmd[1]=browserName.c_str() ;
	}
	else
	{
		m_Cmd[1]="echo No location configured for HTML browser";
		if(missingFiles.size()>0)
		{
			missingFiles+=" and ";
		}
		missingFiles+="a program to browse HTML reports";
	}

	// Finally, report back on the process
	std::string message;
	if(missingFiles.size()==0)
	{
		message="The add-in has configured itself to use";
		message+=m_Cmd[0];
		message+=" to analyze files and ";
		message+=m_Cmd[1];
		message+=" to browse the resulting HTML reports.  ";
		message+="These locations can be changed at any time using the ";
		message+="configuration toolbar button.";
	}
	else
	{
		message="The add-in's self-configuration script has been "
			"unable too find ";
		message+=missingFiles;
		message+=".  You will need to use the configuration toolbar "
			"button to specify a location for the missing program(s) "
			"before using the add-in to analyze files.";
	}

	AfxMessageBox(message.c_str());

	// save the configuration data in the registry.
	saveConfiguration();
}

CString CCommandForm::cmdText(int index)
{
	CString retval;
	if(index>=0 && index<8)
	{
		retval=m_Cmd[index];
	}
	return retval;
}

void CCommandForm::OnDefaults() 
{
	// TODO: Add your control notification handler code here
	setDefaults();	
	EndDialog(IDCANCEL);
}

void CCommandForm::loadConfiguration()
{
	// The VC doco says that the RegCreateKey API is only provided 
	// for legacy compatibility, but it seems to be less fussy
	// than other alternatives.
	HKEY configKey;
	DWORD type;
	unsigned char stringBuffer[BUF_SIZE];
	DWORD sbufLen=BUF_SIZE;

	LONG keyStatus=RegCreateKey(
		registryTopLevelKey,registryKeyPath,&configKey);

	if(keyStatus!=ERROR_SUCCESS)
	{
		// failed to create or open the key
		// fall back on the defaults
		setDefaults();
	}
	else
	{		
		LONG queryStatus=RegQueryValueEx(
			configKey,registryValueName,0,
			&type,stringBuffer,&sbufLen);
		if(queryStatus==ERROR_SUCCESS && type==REG_MULTI_SZ)
		{
			// Success - suck in the values
			int i=0;

			// The Win32 API uses unsigned chars which makes it 
			// unsuitable for passing to strlen etc.
			// Hence we keep two differently typed pointers which
			// we move over the same memory locations.
			unsigned char *uptr=stringBuffer;
			char *ptr=reinterpret_cast<char*>(uptr);
			while(i<8 && uptr<(stringBuffer+sbufLen-2))
			{
				// copy the current null terminated string to a 
				// member of the local array
				m_Cmd[i]=ptr;
				// advance ptr to point to the character after the 
				// terminating zero byte
				ptr+=strlen(ptr)+1;
				uptr+=strlen(ptr)+1;
				i++;
			}
		}
		else
		{
			// Whereas not finding the key is a normal situation for first
			// running the program, finding the key but then not finding the
			// value is an unexpected situation, so we report it.
			AfxMessageBox(
				"Registry value query failed, "
				"default configuration will be used. "
				);
			setDefaults();
		}
		RegCloseKey(configKey);
	}
}

void CCommandForm::saveConfiguration()
{
	HKEY configKey;
	unsigned char stringBuffer[BUF_SIZE];
	DWORD sbufLen=BUF_SIZE;

	LONG keyStatus=RegCreateKey(
		registryTopLevelKey,registryKeyPath,&configKey);

	if(keyStatus!=ERROR_SUCCESS)
	{
		// failed to create or open the key
		// fall back on the defaults
		AfxMessageBox("Failed to open registry key");
		setDefaults();
	}
	else
	{		
		// pump out the values
		int i=0;
		memset(stringBuffer,0,BUF_SIZE);
		
		// The Win32 API uses unsigned chars which makes it 
		// unsuitable for passing to strlen etc.
		// Hence we keep two differently typed pointers which
		// we move over the same memory locations.
		unsigned char *uptr=stringBuffer;
		char *ptr=reinterpret_cast<char*>(uptr);
		while(i<8 && (uptr+strlen(ptr)+2)<(stringBuffer+sbufLen) )
		{
			// copy the current string into the buffer, starting at ptr
			strcpy(ptr,m_Cmd[i]);

			// advance ptr to point to the character after the 
			// terminating zero byte
			ptr+=strlen(ptr)+1;
			uptr+=strlen(ptr)+1;
			i++;
		}
		LONG setStatus=RegSetValueEx(
			configKey,registryValueName,0,
			REG_MULTI_SZ,stringBuffer,sbufLen);
		if(setStatus==ERROR_SUCCESS)
		{
			// success - nothing more to do
		}
		else
		{
			AfxMessageBox("Failed to set registry value");
		}
		RegCloseKey(configKey);
	}

}

