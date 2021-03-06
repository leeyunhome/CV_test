
// ExamMFC001Dlg.h : header file
//

#pragma once

#include "tw_direct_show.h"

// CExamMFC001Dlg dialog
class CExamMFC001Dlg : public CDialogEx
{
private:
	TW_LiveCam m_live_cam;
	TW_PreviewGraphBuilder* mp_preview = NULL;

// Construction
public:
	CExamMFC001Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAMMFC001_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
};
