
// BackgroundColorDlg.h : header file
//

#pragma once


// CBackgroundColorDlg dialog
class CBackgroundColorDlg : public CDialogEx
{
private:
	CBrush m_bk_brush;
// Construction
public:
	CBackgroundColorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BACKGROUNDCOLOR_DIALOG };
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
	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	HRESULT OnCtrlColorDlg(WPARAM wParam, LPARAM lParam);
};
