// DodajNoviRadniNalogDlg.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "DodajNoviRadniNalogDlg.h"
#include "SetRadniNalog.h"


// DodajNoviRadniNalogDlg dialog

IMPLEMENT_DYNAMIC(DodajNoviRadniNalogDlg, CDialogEx)

DodajNoviRadniNalogDlg::DodajNoviRadniNalogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DODAJ_RADNI_NALOG, pParent)
{

}

DodajNoviRadniNalogDlg::~DodajNoviRadniNalogDlg()
{
}

void DodajNoviRadniNalogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_RadniNalog);
}


BEGIN_MESSAGE_MAP(DodajNoviRadniNalogDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &DodajNoviRadniNalogDlg::OnBnClickedSpremi)
END_MESSAGE_MAP()


// DodajNoviRadniNalogDlg message handlers

void DodajNoviRadniNalogDlg::CheckEmptySpace() {
	CEdit* editBoxRadniNalog = (CEdit*)GetDlgItem(IDC_EDIT1);


	if (editBoxRadniNalog == NULL)
		return;
	CString strRadniNalog, er;
	editBoxRadniNalog->GetWindowText(strRadniNalog);
	
	if (strRadniNalog.IsEmpty())
	{
		er.LoadString(IDS_STRING_UNOS_SATI_ERR);
		MessageBox(er);
	}
	else
		UnesiNovogRadniNalog();
}

BOOL DodajNoviRadniNalogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;
}

void DodajNoviRadniNalogDlg::OnBnClickedSpremi()
{
	CheckEmptySpace();;
}

void DodajNoviRadniNalogDlg::UnesiNovogRadniNalog()
{

	SetRadniNalog RecSetRadniNalog;
	long iduciID = 1;

	UpdateData(TRUE);

	CString RadniNalog;
	m_RadniNalog.GetWindowText(RadniNalog);
	
	RecSetRadniNalog.Open();

	if (!RecSetRadniNalog.IsBOF() && !RecSetRadniNalog.IsEOF())
	{
		iduciID = RecSetRadniNalog.MaxID() + 1;
	}

	RecSetRadniNalog.AddNew();
	RecSetRadniNalog.m_id = iduciID;
	RecSetRadniNalog.m_RadniNalog = RadniNalog;
	
	RecSetRadniNalog.Update();
	RecSetRadniNalog.Close();
	EndDialog(IDOK);
}

