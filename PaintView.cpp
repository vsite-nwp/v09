// PaintView.cpp : implementation file
//

#include "stdafx.h"
#include "v9.h"
/*** NWP V9 BEGIN ***/
#include "Doc.h"
/*** NWP V9 END ***/
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
	pDC->Ellipse(static_cast<Doc*>(GetDocument())->rc);
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

/////////////////////////////////////////////////////////////////////////////
// PaintView message handlers





void PaintView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	Invalidate();
}
