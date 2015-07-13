#if !defined(AFX_COMMANDFORM_H__406BC922_AE87_11D3_AFED_444553540000__INCLUDED_)
#define AFX_COMMANDFORM_H__406BC922_AE87_11D3_AFED_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CommandForm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCommandForm dialog

class CCommandForm : public CDialog
{
// Construction
public:
	CCommandForm(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCommandForm();

	virtual void setDefaults();
	void loadConfiguration();
	void saveConfiguration();

	// function to allow access to the strings
	CString cmdText(int index);
	
// Dialog Data
	//{{AFX_DATA(CCommandForm)
	enum { IDD = IDD_DIALOG1 };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommandForm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCommandForm)
	afx_msg void OnDefaults();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_Cmd[8];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMANDFORM_H__406BC922_AE87_11D3_AFED_444553540000__INCLUDED_)
