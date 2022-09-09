// SetRadniSati implementation


#include "pch.h"
#include "stdafx.h"
#include "SetRadniSati.h"

IMPLEMENT_DYNAMIC(SetRadniSati, CRecordset)

SetRadniSati::SetRadniSati(CDatabase* pdb) : CRecordset(pdb)
{
	m_nFields = 7;
	m_nDefaultType = dynaset;
}

CString SetRadniSati::GetDefaultConnect()
{
	return _T("DSN=seminarski;");
}

CString SetRadniSati::GetDefaultSQL()
{
	return _T("[RadniSati]");
}

void SetRadniSati::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);

	RFX_Long(pFX, _T("[ID_Zaposlenici]"), m_id);
	RFX_Date(pFX, _T("[Datum]"), m_Datum);
	RFX_Long(pFX, _T("[Broj radnih sati]"), m_BrojRadnihSati);
	RFX_Text(pFX, _T("[Nalog]"), m_Nalog);
	RFX_Text(pFX, _T("[Opis posla]"), m_Opis);
	RFX_Long(pFX, _T("[ID]"), m_id_uniq);
	RFX_Long(pFX, _T("[ID_RadniNalog]"), m_id_radninalog);

}
/////////////////////////////////////////////////////////////////////////////
// PrimkeSet diagnostics

#ifdef _DEBUG
void SetRadniSati::AssertValid() const
{
	CRecordset::AssertValid();
}

void SetRadniSati::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


long SetRadniSati::MaxID()
{
	MoveLast();
	return m_id;
}