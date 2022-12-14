// PopisOdaberiRadniNalog.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "PopisOdaberiRadniNalog.h"
#include "SetRadniNalog.h"
#include "stdafx.h"

// PopisOdaberiRadniNalog dialog

IMPLEMENT_DYNAMIC(PopisOdaberiRadniNalog, CDialogEx)

PopisOdaberiRadniNalog::PopisOdaberiRadniNalog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_POPIS_ODABERI_RADNI_NALOG, pParent)
{

}

PopisOdaberiRadniNalog::~PopisOdaberiRadniNalog()
{
}

void PopisOdaberiRadniNalog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
	DDX_Text(pDX, IDC_LIST1, m_RadniNalog);
}


BEGIN_MESSAGE_MAP(PopisOdaberiRadniNalog, CDialogEx)
	ON_BN_CLICKED(IDOK, &PopisOdaberiRadniNalog::OnBnClickedOdaberiRadniNalog)
END_MESSAGE_MAP()


// PopisOdaberiRadniNalog message handlers


void PopisOdaberiRadniNalog::OnBnClickedOdaberiRadniNalog()
{
	CString radniNalog, s, id;

	const int pos = ListCtrl.GetNextItem(-1, LVNI_SELECTED);
	if (pos < 0)
	{
		s.LoadString(IDS_STRING_OBAVEZAN_UNOS);
		MessageBox(s);
	}
	else 
	{
		id = ListCtrl.GetItemText(pos, 0);
		radniNalog = ListCtrl.GetItemText(pos, 1);
		m_id = id;
		m_RadniNalog = radniNalog;
		EndDialog(IDOK);
	}
	
}


BOOL PopisOdaberiRadniNalog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString s;

	SetRadniNalog RecSetRadniNalog;
	RecSetRadniNalog.Open();

	s.LoadString(IDS_STRING_ID_RADNI_NALOG);
	ListCtrl.InsertColumn(1, s, LVCFMT_LEFT, 60);
	s.LoadString(IDS_STRING_RADNI_NALOG);
	ListCtrl.InsertColumn(2, s, LVCFMT_LEFT, 250);


	while (!RecSetRadniNalog.IsEOF())
	{
		const int index = ListCtrl.GetItemCount();

		s.Format(_T("%d"), RecSetRadniNalog.m_id);
		ListCtrl.InsertItem(index, s);
		ListCtrl.SetItemText(index, 1, RecSetRadniNalog.m_RadniNalog);

		RecSetRadniNalog.MoveNext();
	}

	RecSetRadniNalog.Close();

	ListCtrl.SetExtendedStyle(ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);



	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}