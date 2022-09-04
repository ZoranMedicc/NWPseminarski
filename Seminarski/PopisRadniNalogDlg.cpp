// PopisRadniNalogDlg.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "PopisRadniNalogDlg.h"
#include "SetRadniNalog.h"
#include "DodajNoviRadniNalogDlg.h"

// PopisRadniNalogDlg dialog

IMPLEMENT_DYNAMIC(PopisRadniNalogDlg, CDialogEx)

PopisRadniNalogDlg::PopisRadniNalogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_POPIS_RANDI_NALOG, pParent)
{

}

PopisRadniNalogDlg::~PopisRadniNalogDlg()
{
}

void PopisRadniNalogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
}


BEGIN_MESSAGE_MAP(PopisRadniNalogDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &PopisRadniNalogDlg::OnBnClickedDodajNoviNalog)
END_MESSAGE_MAP()


// PopisRadniNalogDlg message handlers

BOOL PopisRadniNalogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	PokaziListu();
	PokaziRadneNaloge();

	return TRUE;
}

void PopisRadniNalogDlg::PokaziListu()
{
	CString s;

	s.LoadString(IDS_STRING_ID_RADNI_NALOG);
	ListCtrl.InsertColumn(1, s, LVCFMT_LEFT, 100);
	s.LoadString(IDS_STRING_RADNI_NALOG);
	ListCtrl.InsertColumn(2, s, LVCFMT_CENTER, 250);
}

void PopisRadniNalogDlg::PokaziRadneNaloge()
{
	SetRadniNalog RecSetRadniNalog;

	if (!RecSetRadniNalog.IsOpen())
	{
		RecSetRadniNalog.Open();
	}

	while (!RecSetRadniNalog.IsEOF())
	{
		CString s;
		const int index = ListCtrl.GetItemCount();

		s.Format(_T("%d"), RecSetRadniNalog.m_id);
		ListCtrl.InsertItem(index, s);
		ListCtrl.SetItemText(index, 1, RecSetRadniNalog.m_RadniNalog);

		RecSetRadniNalog.MoveNext();
	}
	RecSetRadniNalog.Close();
	ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
}

void PopisRadniNalogDlg::OnBnClickedDodajNoviNalog()
{
	DodajNoviRadniNalogDlg dlgNoviNalog;
	dlgNoviNalog.DoModal();
	ListCtrl.DeleteAllItems();
	PokaziRadneNaloge();
}
