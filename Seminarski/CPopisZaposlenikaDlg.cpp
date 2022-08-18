// CPopisZaposlenikaDlg.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "CPopisZaposlenikaDlg.h"
#include "SetPopis.h"
#include "CDodajRadnikaDlg.h"


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
	ON_BN_CLICKED(IDOK, &CPopisZaposlenikaDlg::OnBnClickedDodajRadnika)
END_MESSAGE_MAP()


// CPopisZaposlenikaDlg message handlers

void CPopisZaposlenikaDlg::OnZaposleniciPopis() {

	CPopisZaposlenikaDlg PopisZaposlenikaDlg;
	PopisZaposlenikaDlg.DoModal();
}

BOOL CPopisZaposlenikaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	PokaziTablicu();
	PokaziListu();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CPopisZaposlenikaDlg::PokaziTablicu()
{
	CString s;

	s.LoadString(IDS_STRING_ZAPOS_ID);
	ListCtrl.InsertColumn(1, s, LVCFMT_LEFT, 80);
	s.LoadString(IDS_STRING_IME);
	ListCtrl.InsertColumn(2, s, LVCFMT_CENTER, 150);
	s.LoadString(IDS_STRING_PREZIME);
	ListCtrl.InsertColumn(3, s, LVCFMT_CENTER, 150);
	s.LoadString(IDS_STRING_ODJEL);
	ListCtrl.InsertColumn(4, s, LVCFMT_CENTER, 100);
	s.LoadString(IDS_STRING_RADNO_MJESTO);
	ListCtrl.InsertColumn(5, s, LVCFMT_CENTER, 180);
}

void CPopisZaposlenikaDlg::PokaziListu()
{
	SetPopis RecSetPopis;
	RecSetPopis.Open();

	while (!RecSetPopis.IsEOF())
	{
		const int index = ListCtrl.GetItemCount();

		CString s;
		s.Format(_T("%d"), RecSetPopis.m_id);
		ListCtrl.InsertItem(index, s);
		ListCtrl.SetItemText(index, 1, RecSetPopis.m_Ime);
		ListCtrl.SetItemText(index, 2, RecSetPopis.m_Prezime);
		ListCtrl.SetItemText(index, 3, RecSetPopis.m_Odjel);
		ListCtrl.SetItemText(index, 4, RecSetPopis.m_RadnoMjesto);

		RecSetPopis.MoveNext();
	}

	RecSetPopis.Close();

	ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
}

void CPopisZaposlenikaDlg::OnBnClickedDodajRadnika()
{
	// TODO: Add your control notification handler code here
	CDodajRadnikaDlg dlgNoviRadnik;
	dlgNoviRadnik.DoModal();
	ListCtrl.DeleteAllItems();
	PokaziListu();
}
