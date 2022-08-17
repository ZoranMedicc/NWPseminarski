#pragma once
#include "afxdialogex.h"


// CDodajRadnikaDlg dialog

class CDodajRadnikaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDodajRadnikaDlg)

public:
	CDodajRadnikaDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDodajRadnikaDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DODAJ_RADNIKA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDodaj();
	CString m_Ime;
	CString m_Prezime;
	CString m_Odjel;
	CString m_RadnoMjesto;
};
