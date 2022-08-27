// DodajRadneSate.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "DodajRadneSateDlg.h"
#include "UrediRadneSateDlg.h"
#include "PopisOdaberiRadniNalog.h"


// DodajRadneSate dialog

IMPLEMENT_DYNAMIC(DodajRadneSateDlg, CDialogEx)

DodajRadneSateDlg::DodajRadneSateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DODAJ_RADNE_SATE, pParent)

{

}

DodajRadneSateDlg::~DodajRadneSateDlg()
{
}

void DodajRadneSateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT_BROJ_SATI, m_BrojSati);
	//DDX_Text(pDX, IDC_EDIT_OPIS_POSLA, m_Opis);
	//DDX_Control(pDX, IDC_BUTTON_EDIT_RADNI_NALOG, m_edit_RadniNalog);
	//DDX_Text(pDX, IDC_EDIT_RADNI_NALOG, m_RadniNalog);
}


BEGIN_MESSAGE_MAP(DodajRadneSateDlg, CDialogEx)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER_DATUM, &DodajRadneSateDlg::OnDtnDatetimechangeDatetimepickerDatum)
	ON_BN_CLICKED(IDC_BUTTON_EDIT_RADNI_NALOG, &DodajRadneSateDlg::OnBnClickedButtonEditRadniNalog)
END_MESSAGE_MAP()


// DodajRadneSate message handlers


void DodajRadneSateDlg::OnDtnDatetimechangeDatetimepickerDatum(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void DodajRadneSateDlg::OnBnClickedButtonEditRadniNalog()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	PopisOdaberiRadniNalog dlgOdaberiRadniNalog;
	dlgOdaberiRadniNalog.m_RadniNalog = m_RadniNalog;

	if (dlgOdaberiRadniNalog.DoModal() == IDOK)
	{
		m_RadniNalog = dlgOdaberiRadniNalog.m_RadniNalog;
		UpdateData(FALSE);
	}
}
