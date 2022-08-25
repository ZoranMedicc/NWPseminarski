// CDodajRadnikaDlg.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "DodajRadnikaDlg.h"
#include "SetPopis.h"
#include "PopisZaposlenikaDlg.h"


// CDodajRadnikaDlg dialog

IMPLEMENT_DYNAMIC(DodajRadnikaDlg, CDialogEx)

DodajRadnikaDlg::DodajRadnikaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DODAJ_RADNIKA, pParent)

{

}

DodajRadnikaDlg::~DodajRadnikaDlg()
{
}

void DodajRadnikaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_IME, m_Ime);
	DDX_Control(pDX, IDC_EDIT_PREZIME, m_Prezime);
	DDX_Control(pDX, IDC_EDIT_ODJEL, m_Odjel);
	DDX_Control(pDX, IDC_EDIT_RADNO_MJESTO, m_RadnoMjesto);
}


BEGIN_MESSAGE_MAP(DodajRadnikaDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &DodajRadnikaDlg::OnBnClickedDodaj)
END_MESSAGE_MAP()


// CDodajRadnikaDlg message handlers


void DodajRadnikaDlg::OnBnClickedDodaj()
{
	// TODO: Add your control notification handler code here
	CheckEmptySpace();
	//UnesiNovogRadnika();
	
}

void DodajRadnikaDlg::CheckEmptySpace() {
	CEdit* editBoxIme = (CEdit*)GetDlgItem(IDC_EDIT_IME);
	CEdit* editBoxPrezime = (CEdit*)GetDlgItem(IDC_EDIT_PREZIME);
	CEdit* editBoxOdjel = (CEdit*)GetDlgItem(IDC_EDIT_ODJEL);
	CEdit* editBoxRadnoMjesto = (CEdit*)GetDlgItem(IDC_EDIT_RADNO_MJESTO);
	

	if (editBoxIme && editBoxPrezime && editBoxOdjel && editBoxOdjel && editBoxRadnoMjesto == NULL)
		return;
	CString strIme;
	editBoxIme->GetWindowTextW(strIme);
	CString strPrezime;
	editBoxPrezime->GetWindowTextW(strPrezime);
	CString strOdjel;
	editBoxOdjel->GetWindowTextW(strOdjel);
	CString strRadnoMjesto;
	editBoxRadnoMjesto->GetWindowTextW(strRadnoMjesto);
	CString s;
	if (strIme.IsEmpty() || strPrezime.IsEmpty() || strOdjel.IsEmpty() || strRadnoMjesto.IsEmpty())
	{
		AfxMessageBox((IDS_STRING_OBAVEZAN_UNOS), MB_RETRYCANCEL);
	}
	else
		UnesiNovogRadnika();
}


void DodajRadnikaDlg::UnesiNovogRadnika()
{

	SetPopis RecSetPopis;
	long iduciID = 1;

	UpdateData(TRUE);

	CString Ime;
	m_Ime.GetWindowText(Ime);
	CString Prezime;
	m_Prezime.GetWindowText(Prezime);
	CString Odjel;
	m_Odjel.GetWindowText(Odjel);
	CString RadnoMjesto;
	m_RadnoMjesto.GetWindowText(RadnoMjesto);

	if (!RecSetPopis.IsOpen())
	{
		RecSetPopis.Open();
	}

	if (!RecSetPopis.IsBOF() && !RecSetPopis.IsEOF())
	{
		iduciID = RecSetPopis.MaxID() + 1;
	}

	RecSetPopis.AddNew();

	RecSetPopis.m_id = iduciID;
	RecSetPopis.m_Ime = Ime;
	RecSetPopis.m_Prezime = Prezime;
	RecSetPopis.m_Odjel = Odjel;
	RecSetPopis.m_RadnoMjesto = RadnoMjesto;

	RecSetPopis.Update();
	RecSetPopis.Close();
	EndDialog(IDOK);
}


