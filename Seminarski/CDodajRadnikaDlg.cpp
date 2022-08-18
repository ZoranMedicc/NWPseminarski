// CDodajRadnikaDlg.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "CDodajRadnikaDlg.h"
#include "SetPopis.h"
#include "CPopisZaposlenikaDlg.h"


// CDodajRadnikaDlg dialog

IMPLEMENT_DYNAMIC(CDodajRadnikaDlg, CDialogEx)

CDodajRadnikaDlg::CDodajRadnikaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DODAJ_RADNIKA, pParent)

{

}

CDodajRadnikaDlg::~CDodajRadnikaDlg()
{
}

void CDodajRadnikaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_IME, m_Ime);
	DDX_Control(pDX, IDC_EDIT_PREZIME, m_Prezime);
	DDX_Control(pDX, IDC_EDIT_ODJEL, m_Odjel);
	DDX_Control(pDX, IDC_EDIT_RADNO_MJESTO, m_RadnoMjesto);
}


BEGIN_MESSAGE_MAP(CDodajRadnikaDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDodajRadnikaDlg::OnBnClickedDodaj)
END_MESSAGE_MAP()


// CDodajRadnikaDlg message handlers


void CDodajRadnikaDlg::OnBnClickedDodaj()
{
	// TODO: Add your control notification handler code here
	UnesiNovogRadnika();
	EndDialog(IDOK);
}


void CDodajRadnikaDlg::UnesiNovogRadnika()
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
}