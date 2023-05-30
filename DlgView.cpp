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
	ON_EN_KILLFOCUS(IDC_EDIT1, &DlgView::OnKillFocus)
	ON_EN_KILLFOCUS(IDC_EDIT2, &DlgView::OnKillFocus)
	ON_EN_KILLFOCUS(IDC_EDIT3, &DlgView::OnKillFocus)
	ON_EN_KILLFOCUS(IDC_EDIT4, &DlgView::OnKillFocus)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgView construction/destruction

DlgView::DlgView()
	: CFormView(DlgView::IDD)
{
}

DlgView::~DlgView()
{
}

void DlgView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	CRect& rect = GetDocument()->rectangle;

	DDX_Text(pDX, IDC_EDIT1, GetDocument()->rectangle.left);
	DDX_Text(pDX, IDC_EDIT2, GetDocument()->rectangle.top);
	DDX_Text(pDX, IDC_EDIT3, GetDocument()->rectangle.right);
	DDX_Text(pDX, IDC_EDIT4, GetDocument()->rectangle.bottom);
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
void DlgView::OnUpdate(CView*, LPARAM, CObject*) 
{
	UpdateData(true);
}

void DlgView::OnKillFocus() 
{
	UpdateData(true);
	GetDocument()->UpdateAllViews(nullptr);
}

