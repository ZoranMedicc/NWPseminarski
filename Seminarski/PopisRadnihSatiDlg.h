#pragma once
#include "afxdialogex.h"


// PopisRadnihSatiDlg dialog

class PopisRadnihSatiDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PopisRadnihSatiDlg)

public:
	PopisRadnihSatiDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~PopisRadnihSatiDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_POPIS_RADNIH_SATI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	BOOL OnInitDialog();

	void PokaziListu();

	void PokaziRadneSate();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl ListCtrl;

	long m_id;
	int id = 0;
	CTime m_Datum;
	CString m_Datum2;
	long m_BrojRadnihSati;
	CString m_Nalog;
	CString m_Opis;
	afx_msg void OnBnClickedButtonUrediRadneSate();
};
