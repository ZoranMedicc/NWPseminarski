
// SeminarskiView.cpp : implementation of the CSeminarskiView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Seminarski.h"
#endif

#include "SeminarskiDoc.h"
#include "SeminarskiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MainFrm.h"


// CSeminarskiView

IMPLEMENT_DYNCREATE(CSeminarskiView, CView)

BEGIN_MESSAGE_MAP(CSeminarskiView, CView)
END_MESSAGE_MAP()

// CSeminarskiView construction/destruction

CSeminarskiView::CSeminarskiView() noexcept
{
	

}

CSeminarskiView::~CSeminarskiView()
{
}

void CSeminarskiView::OnInitialUpdate()
{
	//...
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	ASSERT(pFrame->IsKindOf(RUNTIME_CLASS(CMainFrame)));
	pFrame->SetWindowText(L"Seminarski - Administracija radnih sati");
	//...
}

BOOL CSeminarskiView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

// CSeminarskiView drawing

void CSeminarskiView::OnDraw(CDC* pDC)
{
	CSeminarskiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect clientRect;
	CString str_seminarski, str_seminarski_upute;
	str_seminarski.Format(IDS_STRING_SEMINARSKI_RAD, 23);
	str_seminarski_upute.Format(IDS_STRING_SEMINARSKI_RAD_UPUTE, 23);
	GetClientRect(clientRect);
	pDC->FillSolidRect(clientRect, RGB(152, 152, 152));
	pDC->TextOutW(300, 300, str_seminarski);
	pDC->TextOutW(290, 500, str_seminarski_upute);

}


// CSeminarskiView diagnostics

#ifdef _DEBUG
void CSeminarskiView::AssertValid() const
{
	CView::AssertValid();
}

void CSeminarskiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSeminarskiDoc* CSeminarskiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSeminarskiDoc)));
	return (CSeminarskiDoc*)m_pDocument;
}
#endif //_DEBUG


// CSeminarskiView message handlers
