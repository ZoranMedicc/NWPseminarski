#pragma once
#include "afxdialogex.h"


// UrediRadniNalogDlg dialog

class UrediRadniNalogDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UrediRadniNalogDlg)

public:
	UrediRadniNalogDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UrediRadniNalogDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_UREDI_RADNI_NALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
	BOOL OnInitDialog();
	void OnBnClickedOk();
	CString m_RadniNalog;
	CString RadniNalog;
	long id;
	long m_id;
	afx_msg void OnBnClickedButtonDelete();
};
