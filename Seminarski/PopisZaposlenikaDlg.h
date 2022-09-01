#pragma once
#include "afxdialogex.h"


// CPopisZaposlenikaDlg dialog

class PopisZaposlenikaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PopisZaposlenikaDlg)

public:
	PopisZaposlenikaDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~PopisZaposlenikaDlg();

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
	long m_zaposleniciID;
	CString m_Ime;
	CString m_Prezime;
	CString m_Odjel;
	CString m_RadnoMjesto;
	CString m_Nalog;
	long m_RadniSati;
	CString m_Opis;
	afx_msg void OnBnClickedDodajRadnika();
	afx_msg void OnBnClickedButtonUredi();
	void PokaziSate();
	afx_msg void OnBnClickedButtonRadniSati();
	CString m_Datum;
	CString s, radniSati, id;
};


