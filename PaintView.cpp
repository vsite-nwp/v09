﻿// PaintView.cpp : implementation file
//

#include "stdafx.h"
#include "v9.h"
#include "Doc.h"
#include "PaintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PaintView

IMPLEMENT_DYNCREATE(PaintView, CView)

PaintView::PaintView()
{
}

PaintView::~PaintView()
{
}


BEGIN_MESSAGE_MAP(PaintView, CView)
	//{{AFX_MSG_MAP(PaintView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PaintView drawing

void PaintView::OnDraw(CDC* pDC)
{
	Doc* pDoc = GetDocument();

	// Crtamo elipsu koristeći koordinate iz dokumenta
	pDC->Ellipse(pDoc->m_rect);
}

void PaintView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	Invalidate();
}

/////////////////////////////////////////////////////////////////////////////
// PaintView diagnostics

#ifdef _DEBUG
void PaintView::AssertValid() const
{
	CView::AssertValid();
}

void PaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

Doc* PaintView::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Doc)));
	return (Doc*)m_pDocument;
}


/////////////////////////////////////////////////////////////////////////////
// PaintView message handlers
