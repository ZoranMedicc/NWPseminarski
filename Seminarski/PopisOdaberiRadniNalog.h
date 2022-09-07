#pragma once
#include "afxdialogex.h"


// PopisOdaberiRadniNalog dialog

class PopisOdaberiRadniNalog : public CDialogEx
{
	DECLARE_DYNAMIC(PopisOdaberiRadniNalog)

public:
	PopisOdaberiRadniNalog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~PopisOdaberiRadniNalog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_POPIS_ODABERI_RADNI_NALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl ListCtrl;
	afx_msg

	void OnBnClickedOdaberiRadniNalog();
	BOOL OnInitDialog();
	CString m_RadniNalog;
};
