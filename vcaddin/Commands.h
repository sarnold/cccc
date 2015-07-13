// Commands.h : header file
//

#if !defined(AFX_COMMANDS_H__2AB447BF_A834_11D3_AFED_444553540000__INCLUDED_)
#define AFX_COMMANDS_H__2AB447BF_A834_11D3_AFED_444553540000__INCLUDED_

#include "CcccDevStudioAddInTypes.h"
#include "DevStudioFileStore.h"

class CCommands : 
	public CComDualImpl<ICommands, &IID_ICommands, &LIBID_CcccDevStudioAddIn>, 
	public CComObjectRoot,
	public CComCoClass<CCommands, &CLSID_Commands>
{
protected:
	IApplication* m_pApplication;

public:
	CCommands();
	~CCommands();
	void SetApplicationObject(IApplication* m_pApplication);

	BEGIN_COM_MAP(CCommands)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ICommands)
	END_COM_MAP()
	DECLARE_NOT_AGGREGATABLE(CCommands)

public:
	STDMETHOD(configureAddIn)();
	STDMETHOD(runCCCCOnWorkspaceFiles)();
	STDMETHOD(runCCCCOnProjectFiles)();
	STDMETHOD(runCCCCOnActiveFile)();
	STDMETHOD(configureCCCCDevStudioAddIn)();

	STDMETHOD(userCommand1)();
	STDMETHOD(userCommand2)();
	STDMETHOD(userCommand3)();
	STDMETHOD(userCommand4)();
	STDMETHOD(userCommand5)();
	STDMETHOD(userCommand6)();

// ICommands methods
	STDMETHOD(CcccDevStudioAddInCommandMethod)(THIS);

private:
	// member variable for the full path to the CCCC binary
	std::string m_CCCCName;
	
	// member variable for the full path to the web browser
	std::string m_BrowserName;

	// A utility function to run a process, copying the process's console
	// output to the Macro tab in the output pane.
	void runProcess(const std::string& commandLine);

	// A utility function to run CCCC on a list of files
	void runCCCC(const FilenameList& fileList);

};

typedef CComObject<CCommands> CCommandsObj;

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMANDS_H__2AB447BF_A834_11D3_AFED_444553540000__INCLUDED)
