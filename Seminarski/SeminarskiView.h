
// SeminarskiView.h : interface of the CSeminarskiView class
//

#pragma once


class CSeminarskiView : public CView
{
protected: // create from serialization only
	CSeminarskiView() noexcept;
	DECLARE_DYNCREATE(CSeminarskiView)

// Attributes
public:
	CSeminarskiDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CSeminarskiView();
	void OnInitialUpdate();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SeminarskiView.cpp
inline CSeminarskiDoc* CSeminarskiView::GetDocument() const
   { return reinterpret_cast<CSeminarskiDoc*>(m_pDocument); }
#endif

