// CPopisZaposlenikaDlg.cpp : implementation file
//

#include "pch.h"
#include "Seminarski.h"
#include "afxdialogex.h"
#include "CPopisZaposlenikaDlg.h"
#include "SetPopis.h"
#include "CDodajRadnikaDlg.h"
#include "UrediRadnikaDlg.h"
#include "PopisRadnihSatiDlg.h"
#include "SetRadniSati.h"


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
	ON_BN_CLICKED(IDC_BUTTON_UREDI, &CPopisZaposlenikaDlg::OnBnClickedButtonUredi)
	ON_BN_CLICKED(IDC_BUTTON_RADNI_SATI, &CPopisZaposlenikaDlg::OnBnClickedButtonRadniSati)
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
	//PokaziSate();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CPopisZaposlenikaDlg::PokaziTablicu()
{
	CString s;

	s.LoadString(IDS_STRING_ZAPOS_ID);
	ListCtrl.InsertColumn(1, s, LVCFMT_LEFT, 100);
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


void CPopisZaposlenikaDlg::OnBnClickedButtonUredi()
{
	// TODO: Add your control notification handler code here
	UrediRadnikaDlg dlgUrediRadnika;
	CString s;

	POSITION pos = ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		s.LoadString(IDS_STRING_OBAVEZAN_ODABIR);
		MessageBox(s);
	}
	else
	{
		while (pos)
		{
			int nItem = ListCtrl.GetNextSelectedItem(pos);
			m_Ime = ListCtrl.GetItemText(nItem, 1);
			m_Prezime = ListCtrl.GetItemText(nItem, 2);
			m_Odjel = ListCtrl.GetItemText(nItem, 3);
			m_RadnoMjesto = ListCtrl.GetItemText(nItem, 4);
		}

		dlgUrediRadnika.m_Ime = m_Ime;
		dlgUrediRadnika.m_Prezime = m_Prezime;
		dlgUrediRadnika.m_Odjel = m_Odjel;
		dlgUrediRadnika.m_RadnoMjesto = m_RadnoMjesto;

		dlgUrediRadnika.DoModal();
		ListCtrl.DeleteAllItems();
		PokaziListu();
	}
}

//void CPopisZaposlenikaDlg::PokaziSate()
//{
//	SetRadniSati RcSetRadniSati;
//	RcSetRadniSati.Open();
//
//	while (!RcSetRadniSati.IsEOF())
//	{
//		const int index = ListCtrl.GetItemCount();
//
//		CTime datum = RcSetRadniSati.m_Datum;
//		CString sDatum = datum.Format(_T("%d.%m.%Y."));
//
//		CString s, radniSati;
//		s.Format(_T("%d"), RcSetRadniSati.m_id);
//		radniSati.Format(_T("%d"), RcSetRadniSati.m_BrojRadnihSati);
//		ListCtrl.InsertItem(index, s);
//		ListCtrl.SetItemText(index, 1, sDatum);
//		ListCtrl.SetItemText(index, 2, radniSati);
//		ListCtrl.SetItemText(index, 3, RcSetRadniSati.m_Nalog);
//		ListCtrl.SetItemText(index, 4, RcSetRadniSati.m_Opis);
//
//		RcSetRadniSati.MoveNext();
//	}
//
//	RcSetRadniSati.Close();
//
//	ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
//}


void CPopisZaposlenikaDlg::OnBnClickedButtonRadniSati()
{
	// TODO: Add your control notification handler code here
	PopisRadnihSatiDlg dlgPopisRadnihSati;
	SetRadniSati RcSetRadniSati;

	CString s, radniSati, id;
	radniSati.Format(_T("%d"), m_RadniSati);
	id.Format(_T("%d"), m_zaposleniciID);

	CTime datum = dlgPopisRadnihSati.m_Datum;
	CString sDatum = datum.Format(_T("%d.%m.%Y."));

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
			sDatum = ListCtrl.GetItemText(nItem, 1);
			radniSati = ListCtrl.GetItemText(nItem, 2);
			m_Nalog = ListCtrl.GetItemText(nItem, 3);
			m_Opis = ListCtrl.GetItemText(nItem, 4);
			

		}

		dlgPopisRadnihSati.m_id = _wtol(id);
		dlgPopisRadnihSati.m_Datum = datum;
		dlgPopisRadnihSati.m_BrojRadnihSati = m_RadniSati;
		dlgPopisRadnihSati.m_Nalog = m_Nalog;
		dlgPopisRadnihSati.m_Opis = m_Opis;
		dlgPopisRadnihSati.DoModal();
	}
	ListCtrl.DeleteAllItems();
	PokaziListu();
}
