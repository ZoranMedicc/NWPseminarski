#pragma once
#include "afxdialogex.h"


// UrediRadnikaDlg dialog

class UrediRadnikaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UrediRadnikaDlg)

public:
	UrediRadnikaDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UrediRadnikaDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_UREDI_RADNIKA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString Ime;
	CString Prezime;
	CString Odjel;
	CString RadnoMjesto;
	afx_msg
		BOOL OnInitDialog();
	void OnBnClickedUredi();
	CString m_Ime;
	CString m_Prezime;
	CString m_Odjel;
	CString m_RadnoMjesto;
	afx_msg void OnBnClickedButtonUredi();
};
