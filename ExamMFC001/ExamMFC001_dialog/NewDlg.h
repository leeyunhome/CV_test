#pragma once


// NewDlg dialog

class NewDlg : public CDialogEx
{
private:
	int m_num;
	DECLARE_DYNAMIC(NewDlg)

public:
	NewDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~NewDlg();

	void SetNum(int a_num) 
	{
		m_num = a_num;
	}

	int GetNum()
	{
		return m_num;
	}

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEW_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedExitBtn();
};
