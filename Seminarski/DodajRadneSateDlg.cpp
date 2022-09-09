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
	DDX_Text(pDX, IDC_EDIT_RADNI_NALOG, m_RadniNalog);

	DDX_Control(pDX, IDC_DATETIMEPICKER_DATUM, m_Date);
}


BEGIN_MESSAGE_MAP(DodajRadneSateDlg, CDialogEx)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER_DATUM, &DodajRadneSateDlg::OnDtnDatetimechangeDatetimepickerDatum)
	ON_BN_CLICKED(IDC_BUTTON_EDIT_RADNI_NALOG, &DodajRadneSateDlg::OnBnClickedButtonEditRadniNalog)
	ON_BN_CLICKED(IDOK, &DodajRadneSateDlg::OnBnClickedSpremi)
//	ON_EN_UPDATE(IDC_EDIT_BROJ_SATI, &DodajRadneSateDlg::OnEnUpdateEditBrojSati)
//ON_EN_UPDATE(IDC_EDIT_BROJ_SATI, &DodajRadneSateDlg::OnEnUpdateEditBrojSati)
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
	UpdateData(TRUE);

	PopisOdaberiRadniNalog dlgOdaberiRadniNalog;
	
	dlgOdaberiRadniNalog.m_RadniNalog = m_RadniNalog;

	if (dlgOdaberiRadniNalog.DoModal() == IDOK)
	{
		m_RadniNalog = dlgOdaberiRadniNalog.m_RadniNalog;
		m_id_radninalog = _wtol(dlgOdaberiRadniNalog.m_id);
		UpdateData(FALSE);
	}
}

void DodajRadneSateDlg::CheckEmptySpace() {
	CEdit* editBoxRadniNalog = (CEdit*)GetDlgItem(IDC_EDIT_RADNI_NALOG);
	CEdit* editBoxDatum = (CEdit*)GetDlgItem(IDC_DATETIMEPICKER_DATUM);
	CEdit* editBoxBrojSati = (CEdit*)GetDlgItem(IDC_EDIT_BROJ_SATI);
	CEdit* editBoxOpis = (CEdit*)GetDlgItem(IDC_EDIT_OPIS_POSLA);

	CString strRadniNalog;
	editBoxRadniNalog->GetWindowText(strRadniNalog);
	CString strDatum;
	editBoxDatum->GetWindowText(strDatum);
	CString strBrojSati;
	editBoxOpis->GetWindowText(strBrojSati);
	CString strOpis;
	editBoxOpis->GetWindowText(strOpis);

	CString s, er;
	if (strRadniNalog.IsEmpty() || strDatum.IsEmpty() || strBrojSati.IsEmpty() || strOpis.IsEmpty())
	{
		er.LoadString(IDS_STRING_OBAVEZAN_UNOS);
		MessageBox(er);
	}
	else
		SpremiRadneSate();
}

void DodajRadneSateDlg::OnBnClickedSpremi()
{
	CheckEmptySpace();
}



void DodajRadneSateDlg::SpremiRadneSate()
{
	SetRadniSati RecSetRadniSati;
	PopisRadnihSatiDlg RecPopisSati;
	PopisZaposlenikaDlg dlgPopisZaposlenika;
	long iduciID = RecPopisSati.m_id;
	CTime t = CTime::GetCurrentTime();
	CString s = t.Format("%d.%m.%Y.");
	CString er;


	UpdateData(TRUE);

	CString RadniNalog;
	CString Datum;
	CString RadniSati;

	m_BrojSati.GetWindowText(RadniSati);
	CString Opis;
	m_Opis.GetWindowText(Opis);


	RecSetRadniSati.Open();


	if (!RecSetRadniSati.IsBOF() && !RecSetRadniSati.IsEOF())
	{
		iduciID = m_id;
	}

	RecSetRadniSati.AddNew();
	m_Datum.ParseDateTime(Datum);
	RecSetRadniSati.m_id = iduciID;
	RecSetRadniSati.m_Nalog = m_RadniNalog;

	if (trig == true) {
		RecSetRadniSati.m_Datum = tnew;
		trig = false;
	}else
		RecSetRadniSati.m_Datum = t;
	if (_wtol(RadniSati) <= 0 || _wtol(RadniSati) > 24) {
		er.LoadString(IDS_STRING_UNOS_SATI_ERR);
		MessageBox(er);
	}
	else {
		RecSetRadniSati.m_BrojRadnihSati = _wtol(RadniSati);
		RecSetRadniSati.m_Opis = Opis;
		RecSetRadniSati.m_id_radninalog = m_id_radninalog;
		RecSetRadniSati.Update();
		RecSetRadniSati.Close();

		EndDialog(IDOK);
	}
	

}

