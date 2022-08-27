// UrediRadnikaDlg.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "UrediRadnikaDlg.h"
#include "PopisZaposlenikaDlg.h"
#include "DodajRadnikaDlg.h"
#include "SetPopis.h"


// UrediRadnikaDlg dialog

IMPLEMENT_DYNAMIC(UrediRadnikaDlg, CDialogEx)

UrediRadnikaDlg::UrediRadnikaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_UREDI_RADNIKA, pParent)
	, m_Ime(_T(""))
	, m_Prezime(_T(""))
	, m_Odjel(_T(""))
	, m_RadnoMjesto(_T(""))
{

}

UrediRadnikaDlg::~UrediRadnikaDlg()
{
}

void UrediRadnikaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_IME, m_Ime);
	DDX_Text(pDX, IDC_EDIT_PREZIME, m_Prezime);
	DDX_Text(pDX, IDC_EDIT_ODJEL, m_Odjel);
	DDX_Text(pDX, IDC_EDIT_RADNO_MJESTO, m_RadnoMjesto);
}


BEGIN_MESSAGE_MAP(UrediRadnikaDlg, CDialogEx)
	//ON_BN_CLICKED(IDOK, &UrediRadnikaDlg::OnBnClickedUredi)
	ON_BN_CLICKED(IDOK, &UrediRadnikaDlg::OnBnClickedButtonUredi)
END_MESSAGE_MAP()


// UrediRadnikaDlg message handlers


BOOL UrediRadnikaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	Ime = m_Ime;
	Prezime = m_Prezime;
	Odjel = m_Odjel;
	RadnoMjesto = m_RadnoMjesto;

	return TRUE;
}



void UrediRadnikaDlg::OnBnClickedButtonUredi()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();

	SetPopis RecSetRadnici;

	UpdateData(TRUE);

	if (!RecSetRadnici.IsOpen())
	{
		RecSetRadnici.Open();
	}

	while (!RecSetRadnici.IsBOF() && !RecSetRadnici.IsEOF())
	{
		if (Ime == RecSetRadnici.m_Ime)
		{
			RecSetRadnici.Edit();

			RecSetRadnici.m_Ime = m_Ime;
			RecSetRadnici.m_Prezime = m_Prezime;
			RecSetRadnici.m_Odjel = m_Odjel;
			RecSetRadnici.m_RadnoMjesto = m_RadnoMjesto;

			RecSetRadnici.Update();
			break;
		}
		RecSetRadnici.MoveNext();
	}
	EndDialog(IDOK);
}
