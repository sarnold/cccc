// AddInMod.cpp : implementation file
//


#include "stdafx.h"

// Turn off warnings due to long names arising out of STL use
#pragma warning ( disable : 4786 4503 )

#include "CcccDevStudioAddIn.h"
#include "DSAddIn.h"
#include "Commands.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// This is called when the user first loads the add-in, and on start-up
//  of each subsequent Developer Studio session
STDMETHODIMP CDSAddIn::OnConnection(IApplication* pApp, VARIANT_BOOL bFirstTime,
		long dwCookie, VARIANT_BOOL* OnConnection)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	// Store info passed to us
	IApplication* pApplication = NULL;
	if (FAILED(pApp->QueryInterface(IID_IApplication, (void**) &pApplication))
		|| pApplication == NULL)
	{
		*OnConnection = VARIANT_FALSE;
		return S_OK;
	}

	m_dwCookie = dwCookie;

	// Create command dispatch, send info back to DevStudio
	CCommandsObj::CreateInstance(&m_pCommands);
	m_pCommands->AddRef();

	// The QueryInterface above AddRef'd the Application object.  It will
	//  be Release'd in CCommand's destructor.
	m_pCommands->SetApplicationObject(pApplication);

	// (see stdafx.h for the definition of VERIFY_OK)

	VERIFY_OK(pApplication->SetAddInInfo((long) AfxGetInstanceHandle(),
		(LPDISPATCH) m_pCommands, IDR_TOOLBAR_MEDIUM, IDR_TOOLBAR_LARGE, m_dwCookie));

	// Inform DevStudio of the commands we implement

	// TODO: Replace the AddCommand call below with a series of calls,
	//  one for each command your add-in will add.

	// The command name should not be localized to other languages.  The 
	//  tooltip, command description, and other strings related to this
	//  command are stored in the string table (IDS_CMD_STRING) and should
	//  be localized.
	addCommand(pApplication,
		"runCCCCOnActiveFile","run CCCC on the active file", 
		0,bFirstTime);
	addCommand(pApplication,
		"runCCCCOnProjectFiles","run CCCC on all files in the active project",
		1,bFirstTime);
	addCommand(pApplication,
		"runCCCCOnWorkspaceFiles","run CCCC on all files in the active workspace", 
		2,bFirstTime);
	addCommand(pApplication,
		"configureCCCCDevStudioAddIn","configure the add-in", 
		3,bFirstTime);

	int i;
	for (i=0; i<6; i++)
	{
		char userCommandName[1024], userCommandTip[1024];
		sprintf(userCommandName,"UserCommand%d",i+1);
		sprintf(userCommandTip,"User defined command #%d",i+1);
		addCommand(pApplication,
			userCommandName,userCommandTip,i+4,bFirstTime);
	}


	*OnConnection = VARIANT_TRUE;
	return S_OK;
}

// This is called on shut-down, and also when the user unloads the add-in
STDMETHODIMP CDSAddIn::OnDisconnection(VARIANT_BOOL bLastTime)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_pCommands->Release();
	m_pCommands = NULL;

	// TODO: Perform any cleanup work here

	return S_OK;
}

void CDSAddIn::addCommand(IApplication* pApp, LPCSTR methodName, LPCSTR methodTip, long imageIndex, VARIANT_BOOL bFirstTime)
{
	VARIANT_BOOL bRet;

	// We can simplify on the MS boilerplate code
	// for this activity by deciding that the command name
	// and the method name will always be the same.
	CComBSTR bszMethodName(methodName);
	CComBSTR bszCmdName(methodName);

	// We still have to build up the command string
	CString strMethodName(methodName);
	CString strCmdString;
	strCmdString=
		strMethodName + "\n" + 
		strMethodName + "\n" +
		methodTip + "\n" + 
		methodTip
	;
	CComBSTR bszCmdString(strCmdString);

	VERIFY_OK(pApp->AddCommand(bszCmdString, bszMethodName, imageIndex, m_dwCookie, &bRet));
	if (bRet == VARIANT_FALSE)
	{
		AfxMessageBox("Failed to load command");
		
	}
	else
	{
		// Add toolbar buttons only if this is the first time the add-in
		//  is being loaded.  Toolbar buttons are automatically remembered
		//  by Developer Studio from session to session, so we should only
		//  add the toolbar buttons once.
		if (bFirstTime == VARIANT_TRUE)
		{
			VERIFY_OK(pApp->
				AddCommandBarButton(dsGlyph, bszCmdName, m_dwCookie));
		}
	}
}
