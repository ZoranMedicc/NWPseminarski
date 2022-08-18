#pragma once
#include "afxdialogex.h"


// CPopisZaposlenikaDlg dialog

class CPopisZaposlenikaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPopisZaposlenikaDlg)

public:
	CPopisZaposlenikaDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPopisZaposlenikaDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_POPIS_ZAPOSLENKA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnZaposleniciPopis();
	BOOL OnInitDialog();
	void PokaziTablicu();
	void PokaziListu();
	CListCtrl ListCtrl;

	CString m_Ime;
	CString m_Prezime;
	CString m_Odjel;
	CString m_RadnoMjesto;
};


