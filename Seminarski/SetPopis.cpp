#include "pch.h"
#include "stdafx.h"
#include "SetPopis.h"

IMPLEMENT_DYNAMIC(SetPopis, CRecordset)

SetPopis::SetPopis(CDatabase* pdb) : CRecordset(pdb)
{
	long m_rb = 0;
	CString m_Ime = _T("");
	CString m_Prezime = _T("");
	CString m_Odjel = _T("");
	CString m_RadnoMjesto = _T("");
	m_nFields = 5;
	m_nDefaultType = dynaset;
}

CString SetPopis::GetDefaultConnect()
{
	return _T("DSN=RadniSati;");
}

CString SetPopis::GetDefaultSQL()
{
	return _T("[Zaposlenici]");
}

void SetPopis::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);

	RFX_Long(pFX, _T("[ID]"), m_rb);
	RFX_Text(pFX, _T("[Ime]"), m_Ime);
	RFX_Text(pFX, _T("[Prezime]"), m_Prezime);
	RFX_Text(pFX, _T("[Odjel]"), m_Odjel);
	RFX_Text(pFX, _T("[Mjesto Rada]"), m_RadnoMjesto);

}
/////////////////////////////////////////////////////////////////////////////
// ArtikliSet diagnostics

#ifdef _DEBUG
void SetPopis::AssertValid() const
{
	CRecordset::AssertValid();
}

void SetPopis::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


long SetPopis::MaxID()
{
	MoveLast();
	return m_rb;
}