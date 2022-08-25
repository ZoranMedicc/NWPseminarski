// UrediRadneSate.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "UrediRadneSateDlg.h"


// UrediRadneSate dialog

IMPLEMENT_DYNAMIC(UrediRadneSateDlg, CDialogEx)

UrediRadneSateDlg::UrediRadneSateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_UREDI_RADNE_SATE, pParent)
	, m_BrojSati(_T(""))
	, m_Opis(_T(""))
	, m_RadniNalog(_T(""))
	, m_Datum(COleDateTime::GetCurrentTime())
{

}

UrediRadneSateDlg::~UrediRadneSateDlg()
{
}

void UrediRadneSateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER_DATUM, DateTimePicker);
	DDX_Text(pDX, IDC_EDIT_BROJ_SATI, m_BrojSati);
	DDX_Text(pDX, IDC_EDIT_OPIS_POSLA, m_Opis);
	DDX_Control(pDX, IDC_BUTTON_EDIT_RADNI_NALOG, m_edit_RadniNalog);
	DDX_Text(pDX, IDC_EDIT_RADNI_NALOG, m_RadniNalog);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATUM, m_Datum);
}


BEGIN_MESSAGE_MAP(UrediRadneSateDlg, CDialogEx)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER_DATUM, &UrediRadneSateDlg::OnDtnDatetimechangeDatetimepickerDatum)
	ON_BN_CLICKED(IDOK, &UrediRadneSateDlg::OnBnClickedSpremi)
END_MESSAGE_MAP()


// UrediRadneSate message handlers


void UrediRadneSateDlg::OnDtnDatetimechangeDatetimepickerDatum(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void UrediRadneSateDlg::OnBnClickedSpremi()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
