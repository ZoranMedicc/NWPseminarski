#pragma once
#include "afxdialogex.h"


// CDodajRadnikaDlg dialog

class DodajRadnikaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DodajRadnikaDlg)

public:
	DodajRadnikaDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DodajRadnikaDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DODAJ_RADNIKA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDodaj();
	void CheckEmptySpace();
	void UnesiNovogRadnika();
	CEdit m_Ime;
	CEdit m_Prezime;
	CEdit m_Odjel;
	CEdit m_RadnoMjesto;
};
