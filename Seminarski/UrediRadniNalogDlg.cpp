// UrediRadniNalogDlg.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "UrediRadniNalogDlg.h"
#include "SetRadniNalog.h"


// UrediRadniNalogDlg dialog

IMPLEMENT_DYNAMIC(UrediRadniNalogDlg, CDialogEx)

UrediRadniNalogDlg::UrediRadniNalogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_UREDI_RADNI_NALOG, pParent)
{

}

UrediRadniNalogDlg::~UrediRadniNalogDlg()
{
}

void UrediRadniNalogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RADNI_NALOG, m_RadniNalog);
}


BEGIN_MESSAGE_MAP(UrediRadniNalogDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &UrediRadniNalogDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &UrediRadniNalogDlg::OnBnClickedButtonDelete)
END_MESSAGE_MAP()


// UrediRadniNalogDlg message handlers

BOOL UrediRadniNalogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	RadniNalog = m_RadniNalog;
	id = m_id;
	return TRUE;
}

void UrediRadniNalogDlg::OnBnClickedOk()
{
	CDialogEx::OnOK();
	SetRadniNalog RecSetRadniNalog;

	UpdateData(TRUE);

	if (!RecSetRadniNalog.IsOpen())
	{
		RecSetRadniNalog.Open();
	}

	while (!RecSetRadniNalog.IsBOF() && !RecSetRadniNalog.IsEOF())
	{
		if (id == RecSetRadniNalog.m_id)
		{
			RecSetRadniNalog.Edit();

			RecSetRadniNalog.m_RadniNalog = m_RadniNalog;
			RecSetRadniNalog.Update();
			break;
		}
		RecSetRadniNalog.MoveNext();
	}
	EndDialog(IDOK);
}


void UrediRadniNalogDlg::OnBnClickedButtonDelete()
{
	SetRadniNalog RecSetRadniNalog;
	UpdateData(TRUE);

	if (!RecSetRadniNalog.IsOpen())
	{
		RecSetRadniNalog.Open();
	}

	while (!RecSetRadniNalog.IsBOF() && !RecSetRadniNalog.IsEOF())
	{
		if (id == RecSetRadniNalog.m_id)
		{
			RecSetRadniNalog.Delete();
		}
		RecSetRadniNalog.MoveNext();
	}
	EndDialog(IDOK);
}
