#pragma once
#include "afxdialogex.h"


// PopisRadniNalogDlg dialog

class PopisRadniNalogDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PopisRadniNalogDlg)

public:
	PopisRadniNalogDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~PopisRadniNalogDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_POPIS_RANDI_NALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};