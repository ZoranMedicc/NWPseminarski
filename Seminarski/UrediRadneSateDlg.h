#pragma once
#include "afxdialogex.h"
#include <afxcontrolbars.h>


// UrediRadneSate dialog

class UrediRadneSateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UrediRadneSateDlg)

public:
	UrediRadneSateDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UrediRadneSateDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_UREDI_RADNE_SATE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDtnDatetimechangeDatetimepickerDatum(NMHDR* pNMHDR, LRESULT* pResult);
	CDateTimeCtrl DateTimePicker;
	CString m_BrojSati;
	CString m_Opis;
	afx_msg void OnBnClickedSpremi();
	CButton m_edit_RadniNalog;
	CString m_RadniNalog;
	//CString m_Datum;
	COleDateTime m_Datum;
};
