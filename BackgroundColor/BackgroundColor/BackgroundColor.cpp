
// BackgroundColor.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "BackgroundColor.h"
#include "BackgroundColorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBackgroundColorApp

BEGIN_MESSAGE_MAP(CBackgroundColorApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CBackgroundColorApp construction

CBackgroundColorApp::CBackgroundColorApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CBackgroundColorApp object

CBackgroundColorApp theApp;


// CBackgroundColorApp initialization

BOOL CBackgroundColorApp::InitInstance()
{

	CWinApp::InitInstance();

	//SetDialogBkColor(RGB(0, 200, 255), RGB(0, 0, 128));
	
	CBackgroundColorDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

