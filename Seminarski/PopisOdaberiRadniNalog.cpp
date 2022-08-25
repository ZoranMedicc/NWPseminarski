// PopisOdaberiRadniNalog.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "PopisOdaberiRadniNalog.h"


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
}


BEGIN_MESSAGE_MAP(PopisOdaberiRadniNalog, CDialogEx)
END_MESSAGE_MAP()


// PopisOdaberiRadniNalog message handlers
