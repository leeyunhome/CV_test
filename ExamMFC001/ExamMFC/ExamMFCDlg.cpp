
// ExamMFCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ExamMFC.h"
#include "ExamMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamMFCDlg dialog



CExamMFCDlg::CExamMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXAMMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExamMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CExamMFCDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CExamMFCDlg message handlers

BOOL CExamMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_my_edit.Attach(GetDlgItem(IDC_EDIT1)->m_hWnd);
	m_my_list_box.Attach(GetDlgItem(IDC_LIST1)->m_hWnd);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CExamMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CExamMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExamMFCDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	m_my_edit.Detach();
	m_my_list_box.Detach();
}


void CExamMFCDlg::OnBnClickedButton1()
{
	CString str;
	m_my_edit.GetWindowTextW(str);

	int index = m_my_list_box.InsertString(-1, str);
	m_my_list_box.SetCurSel(index);

	m_my_edit.SetWindowTextW(L"");
}
