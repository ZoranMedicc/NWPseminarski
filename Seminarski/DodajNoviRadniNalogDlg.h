#pragma once
#include "afxdialogex.h"


// DodajNoviRadniNalogDlg dialog

class DodajNoviRadniNalogDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DodajNoviRadniNalogDlg)

public:
	DodajNoviRadniNalogDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DodajNoviRadniNalogDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DODAJ_RADNI_NALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_RadniNalog;
	afx_msg
		
	void CheckEmptySpace();
	BOOL OnInitDialog();
	void OnBnClickedSpremi();
	void UnesiNovogRadniNalog();
};
