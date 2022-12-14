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
	BOOL OnInitDialog();
	CDateTimeCtrl DateTimePicker;
	CString m_BrojSati;
	CString BrojSati;
	CString m_Opis;
	CString Opis;
	afx_msg void OnBnClickedSpremi();
	CButton m_edit_RadniNalog;
	CString m_RadniNalog;
	CString RadniNalog;
	CString m_Datum2;
	COleDateTime m_Datum;
	COleDateTime Datum;
	afx_msg void OnBnClickedButtonEditRadniNalog();
	afx_msg void OnBnClickedButtonDelete();
	long m_id_uniq;
	long id_uniq;
	long m_id_radninalog;
	long id_radninalog;
//	afx_msg void OnEnUpdateEditBrojSati();
};
