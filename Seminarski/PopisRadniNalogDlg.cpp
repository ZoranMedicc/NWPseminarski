// PopisRadniNalogDlg.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "PopisRadniNalogDlg.h"
#include "SetRadniNalog.h"
#include "DodajNoviRadniNalogDlg.h"
#include "UrediRadniNalogDlg.h"

// PopisRadniNalogDlg dialog

IMPLEMENT_DYNAMIC(PopisRadniNalogDlg, CDialogEx)

PopisRadniNalogDlg::PopisRadniNalogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_POPIS_RADNI_NALOG, pParent)
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
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &PopisRadniNalogDlg::OnBnClickedButtonEdit)
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
	ListCtrl.InsertColumn(2, s, LVCFMT_LEFT, 250);
}

void PopisRadniNalogDlg::PokaziRadneNaloge()
{
	SetRadniNalog RecSetRadniNalog;

	RecSetRadniNalog.Open();

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


void PopisRadniNalogDlg::OnBnClickedButtonEdit()
{
	UrediRadniNalogDlg dlgUrediRadniNalog;
	CString s;

	const int pos = ListCtrl.GetNextItem(-1, LVNI_SELECTED);
	if (pos < NULL)
	{
		s.LoadString(IDS_STRING_OBAVEZAN_ODABIR);
		MessageBox(s);
	}
	else
	{
		m_id = ListCtrl.GetItemText(pos, 0);
		m_RadniNalog = ListCtrl.GetItemText(pos, 1);
		
		dlgUrediRadniNalog.m_id = _wtol(m_id);
		dlgUrediRadniNalog.m_RadniNalog = m_RadniNalog;
		dlgUrediRadniNalog.DoModal();
		ListCtrl.DeleteAllItems();
		PokaziRadneNaloge();
	}
}
