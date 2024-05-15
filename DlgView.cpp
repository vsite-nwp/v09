// DlgView.cpp : implementation of the DlgView class
//

#include "stdafx.h"
#include "v9.h"

#include "Doc.h"
#include "DlgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgView

IMPLEMENT_DYNCREATE(DlgView, CFormView)

BEGIN_MESSAGE_MAP(DlgView, CFormView)
	//{{AFX_MSG_MAP(DlgView)
	//}}AFX_MSG_MAP
	ON_EN_KILLFOCUS(IDC_EDIT1, &DlgView::OnEnKillfocus)
	ON_EN_KILLFOCUS(IDC_EDIT2, &DlgView::OnEnKillfocus)
	ON_EN_KILLFOCUS(IDC_EDIT3, &DlgView::OnEnKillfocus)
	ON_EN_KILLFOCUS(IDC_EDIT4, &DlgView::OnEnKillfocus)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgView construction/destruction

DlgView::DlgView()
	: CFormView(DlgView::IDD)
	
	 /*top(_T(""))
	, right(_T(""))
	, bottom(_T(""))*/
{
}

DlgView::~DlgView()
{
}

void DlgView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgView)
	//}}AFX_DATA_MAP

	DDX_Text(pDX, IDC_EDIT1, GetDocument()->rt.left);
	DDX_Text(pDX, IDC_EDIT2, GetDocument()->rt.top);
	DDX_Text(pDX, IDC_EDIT3, GetDocument()->rt.right);
	DDX_Text(pDX, IDC_EDIT4, GetDocument()->rt.bottom);
}

BOOL DlgView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFormView::PreCreateWindow(cs);
}

void DlgView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();

}
void DlgView::OnUpdate(CView*, LPARAM, CObject*)
{
	UpdateData(false);
}

void DlgView::OnEnKillfocus()
{
	UpdateData(true);
	GetDocument()->UpdateAllViews(nullptr);
}

/////////////////////////////////////////////////////////////////////////////
// DlgView diagnostics

#ifdef _DEBUG
void DlgView::AssertValid() const
{
	CFormView::AssertValid();
}

void DlgView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Doc* DlgView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Doc)));
	return (Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// DlgView message handlers

