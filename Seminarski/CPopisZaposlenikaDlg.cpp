// CPopisZaposlenikaDlg.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "CPopisZaposlenikaDlg.h"


// CPopisZaposlenikaDlg dialog

IMPLEMENT_DYNAMIC(CPopisZaposlenikaDlg, CDialogEx)

CPopisZaposlenikaDlg::CPopisZaposlenikaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_POPIS_ZAPOSLENKA, pParent)
{

}

CPopisZaposlenikaDlg::~CPopisZaposlenikaDlg()
{
}

void CPopisZaposlenikaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
	DDX_Text(pDX, IDC_LIST1, m_Ime);
	DDX_Text(pDX, IDC_LIST1, m_Prezime);
	DDX_Text(pDX, IDC_LIST1, m_Odjel);
	DDX_Text(pDX, IDC_LIST1, m_RadnoMjesto);
}


BEGIN_MESSAGE_MAP(CPopisZaposlenikaDlg, CDialogEx)
	ON_COMMAND(ID_ZAPOSLENICI_POPIS, &CPopisZaposlenikaDlg::OnZaposleniciPopis)
END_MESSAGE_MAP()


// CPopisZaposlenikaDlg message handlers

void CPopisZaposlenikaDlg::OnZaposleniciPopis() {

	CPopisZaposlenikaDlg PopisZaposlenikaDlg;
	PopisZaposlenikaDlg.DoModal();
}

