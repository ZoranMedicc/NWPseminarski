// PopisRadnihSatiDlg.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "PopisRadnihSatiDlg.h"
#include "SetRadniSati.h"
#include <iostream>
#include <string>
#include "SetPopis.h"
#include "UrediRadneSateDlg.h"
#include "PopisZaposlenikaDlg.h"
#include "SetRadniNalog.h"
#include "DodajRadneSateDlg.h"

// PopisRadnihSatiDlg dialog

IMPLEMENT_DYNAMIC(PopisRadnihSatiDlg, CDialogEx)

PopisRadnihSatiDlg::PopisRadnihSatiDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_POPIS_RADNIH_SATI, pParent)
	, m_id(0)
{

}

PopisRadnihSatiDlg::~PopisRadnihSatiDlg()
{
}

void PopisRadnihSatiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
}


BEGIN_MESSAGE_MAP(PopisRadnihSatiDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_UREDI_RADNE_SATE, &PopisRadnihSatiDlg::OnBnClickedButtonUrediRadneSate)
	ON_BN_CLICKED(IDC_BUTTON_DODAJ_RADNE_SATE, &PopisRadnihSatiDlg::OnBnClickedButtonDodajRadneSate)
END_MESSAGE_MAP()

// PopisRadnihSatiDlg message handlers

BOOL PopisRadnihSatiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	PokaziListu();
	PokaziRadneSate();

	return TRUE;
}

void PopisRadnihSatiDlg::PokaziListu()
{
	CString s;

	s.LoadString(IDS_STRING_ZAPOS_ID);
	ListCtrl.InsertColumn(1, s, LVCFMT_LEFT, 100);
	s.LoadString(IDS_STRING_DATUM);
	ListCtrl.InsertColumn(2, s, LVCFMT_CENTER, 150);
	s.LoadString(IDS_STRING_BROJ_RADNIH_SATI);
	ListCtrl.InsertColumn(3, s, LVCFMT_CENTER, 100);
	s.LoadString(IDS_STRING_RADNI_NALOG);
	ListCtrl.InsertColumn(4, s, LVCFMT_CENTER, 200);
	s.LoadString(IDS_STRING_OPIS);
	ListCtrl.InsertColumn(5, s, LVCFMT_CENTER, 200);
}

void PopisRadnihSatiDlg::PokaziRadneSate()
{
	SetRadniSati RecSetRadniSati;

	if (!RecSetRadniSati.IsOpen())
	{
		RecSetRadniSati.Open();
	}

	while (!RecSetRadniSati.IsEOF())
	{
		long radnisati_ID = m_id;

		if (RecSetRadniSati.m_id == radnisati_ID)
		{
			id++;
			const int index = ListCtrl.GetItemCount();
			CTime datum = RecSetRadniSati.m_Datum;
			CString sDatum = datum.Format(_T("%d/%m/%Y"));

			CString s, radniSati;
			s.Format(_T("%d"), RecSetRadniSati.m_id);
			radniSati.Format(_T("%d"), RecSetRadniSati.m_BrojRadnihSati);
			ListCtrl.InsertItem(index, s);
			ListCtrl.SetItemText(index, 1, sDatum);
			ListCtrl.SetItemText(index, 2, radniSati);
			ListCtrl.SetItemText(index, 3, RecSetRadniSati.m_Nalog);
			ListCtrl.SetItemText(index, 4, RecSetRadniSati.m_Opis);
		}
		RecSetRadniSati.MoveNext();
	}
	RecSetRadniSati.Close();
	ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
}

void PopisRadnihSatiDlg::OnBnClickedButtonUrediRadneSate()
{
	// TODO: Add your control notification handler code here
	UrediRadneSateDlg dlgUrediRadneSate;
	SetRadniSati RcSetRadniSati;

	CString s, radniSati, id;
	radniSati.Format(_T("%d"), dlgUrediRadneSate.m_BrojSati);
	//id.Format(_T("%d"), m_zaposleniciID);

	POSITION pos = ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		s.LoadString(IDS_STRING_OBAVEZAN_UNOS);
		MessageBox(s);
	}
	else
	{
		while (pos)
		{
			int nItem = ListCtrl.GetNextSelectedItem(pos);
			id = ListCtrl.GetItemText(nItem, 0);
			m_Datum2 = ListCtrl.GetItemText(nItem, 1);
			radniSati = ListCtrl.GetItemText(nItem, 2);
			m_Nalog = ListCtrl.GetItemText(nItem, 3);
			m_Opis = ListCtrl.GetItemText(nItem, 4);


		}

		//dlgUrediRadneSate.m_id = _wtol(id);

		COleDateTime dt;
		dt.ParseDateTime(m_Datum2, 0UL, 1024UL);
		dlgUrediRadneSate.m_Datum = dt;
		dlgUrediRadneSate.m_BrojSati = radniSati;
		dlgUrediRadneSate.m_RadniNalog = m_Nalog;
		dlgUrediRadneSate.m_Opis = m_Opis;
		//dlgUrediRadneSate.DoModal();
	}
	dlgUrediRadneSate.DoModal();
	ListCtrl.DeleteAllItems();
	PokaziRadneSate();
}


void PopisRadnihSatiDlg::OnBnClickedButtonDodajRadneSate()
{
	// TODO: Add your control notification handler code here
	DodajRadneSateDlg dlgNoviRadniSati;
	dlgNoviRadniSati.DoModal();
	ListCtrl.DeleteAllItems();
	PokaziRadneSate();
}
