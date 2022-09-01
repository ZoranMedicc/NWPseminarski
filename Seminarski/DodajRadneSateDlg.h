#pragma once
#include "afxdialogex.h"


// DodajRadneSate dialog

class DodajRadneSateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DodajRadneSateDlg)

public:
	DodajRadneSateDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DodajRadneSateDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DODAJ_RADNE_SATE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDtnDatetimechangeDatetimepickerDatum(NMHDR* pNMHDR, LRESULT* pResult);
	BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonEditRadniNalog();
	void CheckEmptySpace();
	void OnBnClickedSpremi();
	CEdit m_Opis;
	CEdit m_BrojSati;
	CEdit m_RadniNalog;
	CEdit m_Datum2;
	CButton m_edit_RadniNalog;
	afx_msg void SpremiRadneSate();
	COleDateTime m_Datum;
	CDateTimeCtrl m_Date;
	CDateTimeCtrl m_dateTimeCtrl;
	long m_id=0;
	COleDateTime Datum;
	CTime tnew;
	bool trig = false;

};
