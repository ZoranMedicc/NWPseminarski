#include "pch.h"
#include "stdafx.h"
#include "SetRadniNalog.h"

IMPLEMENT_DYNAMIC(SetRadniNalog, CRecordset)

SetRadniNalog::SetRadniNalog(CDatabase* pdb) : CRecordset(pdb)
{
	long m_id = 0;
	CString m_RadniNalog = _T("");
	m_nFields = 2;
	m_nDefaultType = dynaset;
}

CString SetRadniNalog::GetDefaultConnect()
{
	return _T("DSN=seminarski;");
}

CString SetRadniNalog::GetDefaultSQL()
{
	return _T("[RadniNalog]");
}

void SetRadniNalog::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);

	RFX_Long(pFX, _T("[ID]"), m_id);
	RFX_Text(pFX, _T("[Nalog]"), m_RadniNalog);

}
/////////////////////////////////////////////////////////////////////////////
// ArtikliSet diagnostics

#ifdef _DEBUG
void SetRadniNalog::AssertValid() const
{
	CRecordset::AssertValid();
}

void SetRadniNalog::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


long SetRadniNalog::MaxID()
{
	MoveLast();
	return m_id;
}