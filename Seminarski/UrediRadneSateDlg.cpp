// UrediRadneSate.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "UrediRadneSateDlg.h"
#include "PopisOdaberiRadniNalog.h"
#include "SetRadniSati.h"
#include <ctime>
#include "PopisRadnihSatiDlg.h"


// UrediRadneSate dialog

IMPLEMENT_DYNAMIC(UrediRadneSateDlg, CDialogEx)

UrediRadneSateDlg::UrediRadneSateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_UREDI_RADNE_SATE, pParent)
	, m_BrojSati(_T(""))
	, m_Opis(_T(""))
	, m_RadniNalog(_T(""))
	, m_Datum(COleDateTime::GetCurrentTime())
	, m_id_uniq(0)
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
	ON_BN_CLICKED(IDC_BUTTON_EDIT_RADNI_NALOG, &UrediRadneSateDlg::OnBnClickedButtonEditRadniNalog)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &UrediRadneSateDlg::OnBnClickedButtonDelete)
END_MESSAGE_MAP()


// UrediRadneSate message handlers


void UrediRadneSateDlg::OnDtnDatetimechangeDatetimepickerDatum(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	*pResult = 0;
}

BOOL UrediRadneSateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	PopisRadnihSatiDlg dlgSati;
	RadniNalog = m_RadniNalog;
	Opis = m_Opis;
	BrojSati = m_BrojSati;
	Datum = m_Datum;
	id_uniq = m_id_uniq;
	return TRUE;
}


void UrediRadneSateDlg::OnBnClickedSpremi()
{
	CDialogEx::OnOK();
	SetRadniSati RecSetRadniSati;
	SYSTEMTIME d;
	COleDateTime dt = m_Datum;
	dt.GetAsSystemTime(d);
	
	UpdateData(TRUE);

	if (!RecSetRadniSati.IsOpen())
	{
		RecSetRadniSati.Open();
	}

	while (!RecSetRadniSati.IsBOF() && !RecSetRadniSati.IsEOF())
	{
		if (Opis == RecSetRadniSati.m_Opis )
		{
			RecSetRadniSati.Edit();

			RecSetRadniSati.m_Nalog = m_RadniNalog;
			RecSetRadniSati.m_Opis = m_Opis;
			RecSetRadniSati.m_BrojRadnihSati = _wtol(m_BrojSati);
			RecSetRadniSati.m_Datum = CTime(d);

			RecSetRadniSati.Update();
			break;
		}
		RecSetRadniSati.MoveNext();
	}
	EndDialog(IDOK);
	
}


void UrediRadneSateDlg::OnBnClickedButtonEditRadniNalog()
{
	UpdateData(TRUE);

	PopisOdaberiRadniNalog dlgOdaberiRadniNalog;
	dlgOdaberiRadniNalog.m_RadniNalog = m_RadniNalog;

	if (dlgOdaberiRadniNalog.DoModal() == IDOK)
	{
		m_RadniNalog = dlgOdaberiRadniNalog.m_RadniNalog;
		UpdateData(FALSE);
	}
}


void UrediRadneSateDlg::OnBnClickedButtonDelete()
{
	SetRadniSati RecSetRadniSati;
	SYSTEMTIME d;
	COleDateTime dt = m_Datum;
	dt.GetAsSystemTime(d);
	UpdateData(TRUE);

	if (!RecSetRadniSati.IsOpen())
	{
		RecSetRadniSati.Open();
	}

	while (!RecSetRadniSati.IsBOF() && !RecSetRadniSati.IsEOF())
	{
		if (id_uniq == RecSetRadniSati.m_id_uniq)
		{
			RecSetRadniSati.Delete();
		}
		RecSetRadniSati.MoveNext();
	}
	EndDialog(IDOK);
}
