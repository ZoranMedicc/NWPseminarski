// DodajRadneSate.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "DodajRadneSateDlg.h"
#include "UrediRadneSateDlg.h"
#include "PopisOdaberiRadniNalog.h"
#include "SetRadniSati.h"
#include "PopisRadnihSatiDlg.h"
#include "PopisZaposlenikaDlg.h"


// DodajRadneSate dialog

IMPLEMENT_DYNAMIC(DodajRadneSateDlg, CDialogEx)

DodajRadneSateDlg::DodajRadneSateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DODAJ_RADNE_SATE, pParent)
	, m_id(0)
{

}

DodajRadneSateDlg::~DodajRadneSateDlg()
{
}

void DodajRadneSateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_BROJ_SATI, m_BrojSati);
	DDX_Control(pDX, IDC_EDIT_OPIS_POSLA, m_Opis);
	DDX_Control(pDX, IDC_BUTTON_EDIT_RADNI_NALOG, m_edit_RadniNalog);
	DDX_Control(pDX, IDC_EDIT_RADNI_NALOG, m_RadniNalog);

	DDX_Control(pDX, IDC_DATETIMEPICKER_DATUM, m_Date);
}


BEGIN_MESSAGE_MAP(DodajRadneSateDlg, CDialogEx)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER_DATUM, &DodajRadneSateDlg::OnDtnDatetimechangeDatetimepickerDatum)
	ON_BN_CLICKED(IDC_BUTTON_EDIT_RADNI_NALOG, &DodajRadneSateDlg::OnBnClickedButtonEditRadniNalog)
	ON_BN_CLICKED(IDOK, &DodajRadneSateDlg::OnBnClickedSpremi)
END_MESSAGE_MAP()


// DodajRadneSate message handlers


void DodajRadneSateDlg::OnDtnDatetimechangeDatetimepickerDatum(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	
	this->m_Date.GetTime(tnew);
	CString s = tnew.Format("%d.%m.%Y.");
	trig = true;
	*pResult = 0;
	
}

BOOL DodajRadneSateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	Datum = m_Datum;

	return TRUE;
}

void DodajRadneSateDlg::OnBnClickedButtonEditRadniNalog()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	PopisOdaberiRadniNalog dlgOdaberiRadniNalog;
	CString strRadniNalog;
	m_RadniNalog.GetWindowText(strRadniNalog);
	dlgOdaberiRadniNalog.m_RadniNalog = strRadniNalog;

	if (dlgOdaberiRadniNalog.DoModal() == IDOK)
	{
		strRadniNalog = dlgOdaberiRadniNalog.m_RadniNalog;
		
		UpdateData(FALSE);
	}
}

void DodajRadneSateDlg::CheckEmptySpace() {
	CEdit* editBoxRadniNalog = (CEdit*)GetDlgItem(IDC_EDIT_RADNI_NALOG);
	CEdit* editBoxDatum = (CEdit*)GetDlgItem(IDC_DATETIMEPICKER_DATUM);
	CEdit* editBoxBrojSati = (CEdit*)GetDlgItem(IDC_EDIT_BROJ_SATI);
	CEdit* editBoxOpis = (CEdit*)GetDlgItem(IDC_EDIT_OPIS_POSLA);


	if (editBoxRadniNalog && editBoxDatum && editBoxBrojSati && editBoxOpis == NULL)
		return;
	CString strRadniNalog;
	editBoxRadniNalog->GetWindowTextW(strRadniNalog);
	CString strDatum;
	editBoxDatum->GetWindowTextW(strDatum);
	CString strBrojSati;
	editBoxOpis->GetWindowTextW(strBrojSati);
	CString strOpis;
	editBoxOpis->GetWindowTextW(strOpis);

	CString s;
	if (strRadniNalog.IsEmpty() || strDatum.IsEmpty() || strBrojSati.IsEmpty() || strOpis.IsEmpty())
	{
		AfxMessageBox((IDS_STRING_OBAVEZAN_UNOS), MB_RETRYCANCEL);
	}
	else
		SpremiRadneSate();
}

void DodajRadneSateDlg::OnBnClickedSpremi()
{
	// TODO: Add your control notification handler code here
	CheckEmptySpace();
	//UnesiNovogRadnika();

}



void DodajRadneSateDlg::SpremiRadneSate()
{
	// TODO: Add your control notification handler code here
	SetRadniSati RecSetRadniSati;
	PopisRadnihSatiDlg RecPopisSati;
	PopisZaposlenikaDlg dlgPopisZaposlenika;
	long iduciID = RecPopisSati.m_id;
	CTime t = CTime::GetCurrentTime();
	CString s = t.Format("%d.%m.%Y.");


	UpdateData(TRUE);

	CString RadniNalog;
	m_RadniNalog.GetWindowText(RadniNalog);
	CString Datum;
	//s.SetWindowText(Datum);
	CString RadniSati;
	m_BrojSati.GetWindowText(RadniSati);
	CString Opis;
	m_Opis.GetWindowText(Opis);

	if (!RecSetRadniSati.IsOpen())
	{
		RecSetRadniSati.Open();
	}

	if (!RecSetRadniSati.IsBOF() && !RecSetRadniSati.IsEOF())
	{
		iduciID = m_id;
	}

	RecSetRadniSati.AddNew();
	m_Datum.ParseDateTime(Datum);
	RecSetRadniSati.m_id = iduciID;
	RecSetRadniSati.m_Nalog = RadniNalog;

	if (trig == true) {
		RecSetRadniSati.m_Datum = tnew;
		trig = false;
	}else
		RecSetRadniSati.m_Datum = t;
	
	RecSetRadniSati.m_BrojRadnihSati = _wtol(RadniSati);
	RecSetRadniSati.m_Opis = Opis;

	RecSetRadniSati.Update();
	RecSetRadniSati.Close();

	EndDialog(IDOK);


}
