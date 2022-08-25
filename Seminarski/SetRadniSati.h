#pragma once
#include <afxdb.h>

class SetRadniSati : public CRecordset
{
public:
	SetRadniSati(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(SetRadniSati)

	long m_id;
	CTime m_Datum;
	long m_BrojRadnihSati;
	CString m_Nalog;
	CString m_Opis;

public:
	virtual CString GetDefaultConnect();	// Default connection string

	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	long MaxID();
};

#pragma once
