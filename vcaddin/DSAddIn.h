// DSAddIn.h : header file
//

#if !defined(AFX_DSADDIN_H__2AB447BD_A834_11D3_AFED_444553540000__INCLUDED_)
#define AFX_DSADDIN_H__2AB447BD_A834_11D3_AFED_444553540000__INCLUDED_

#include "commands.h"

// {2AB447AA-A834-11D3-AFED-444553540000}
DEFINE_GUID(CLSID_DSAddIn,
0x2ab447aa, 0xa834, 0x11d3, 0xaf, 0xed, 0x44, 0x45, 0x53, 0x54, 0, 0);

/////////////////////////////////////////////////////////////////////////////
// CDSAddIn

class CDSAddIn : 
	public IDSAddIn,
	public CComObjectRoot,
	public CComCoClass<CDSAddIn, &CLSID_DSAddIn>
{
public:
	DECLARE_REGISTRY(CDSAddIn, "CcccDevStudioAddIn.DSAddIn.1",
		"CCCCDEVSTUDIOADDIN Developer Studio Add-in", IDS_CCCCDEVSTUDIOADDIN_LONGNAME,
		THREADFLAGS_BOTH)

	CDSAddIn() {}
	BEGIN_COM_MAP(CDSAddIn)
		COM_INTERFACE_ENTRY(IDSAddIn)
	END_COM_MAP()
	DECLARE_NOT_AGGREGATABLE(CDSAddIn)

// IDSAddIns
public:
	STDMETHOD(OnConnection)(THIS_ IApplication* pApp, VARIANT_BOOL bFirstTime,
		long dwCookie, VARIANT_BOOL* OnConnection);
	STDMETHOD(OnDisconnection)(THIS_ VARIANT_BOOL bLastTime);

protected:
	CCommandsObj* m_pCommands;
	DWORD m_dwCookie;
private:
	void addCommand(IApplication* pApp, LPCSTR methodName, LPCSTR methodTip, long imageIndex, VARIANT_BOOL bFirstTime);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DSADDIN_H__2AB447BD_A834_11D3_AFED_444553540000__INCLUDED)
