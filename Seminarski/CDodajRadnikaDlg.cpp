// CDodajRadnikaDlg.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "CDodajRadnikaDlg.h"


// CDodajRadnikaDlg dialog

IMPLEMENT_DYNAMIC(CDodajRadnikaDlg, CDialogEx)

CDodajRadnikaDlg::CDodajRadnikaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DODAJ_RADNIKA, pParent)
	, m_Ime(_T(""))
	, m_Prezime(_T(""))
	, m_Odjel(_T(""))
	, m_RadnoMjesto(_T(""))
{

}

CDodajRadnikaDlg::~CDodajRadnikaDlg()
{
}

void CDodajRadnikaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_IME, m_Ime);
	DDX_Text(pDX, IDC_EDIT_PREZIME, m_Prezime);
	DDX_Text(pDX, IDC_EDIT_ODJEL, m_Odjel);
	DDX_Text(pDX, IDC_EDIT_RADNO_MJESTO, m_RadnoMjesto);
}


BEGIN_MESSAGE_MAP(CDodajRadnikaDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDodajRadnikaDlg::OnBnClickedDodaj)
END_MESSAGE_MAP()


// CDodajRadnikaDlg message handlers


void CDodajRadnikaDlg::OnBnClickedDodaj()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
