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
	ON_EN_KILLFOCUS(IDC_EDIT1, &DlgView::OnEnKillFocusEdit)
	ON_EN_KILLFOCUS(IDC_EDIT2, &DlgView::OnEnKillFocusEdit)
	ON_EN_KILLFOCUS(IDC_EDIT3, &DlgView::OnEnKillFocusEdit)
	ON_EN_KILLFOCUS(IDC_EDIT4, &DlgView::OnEnKillFocusEdit)
	//}}AFX_MSG_MAP
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
	//{{AFX_DATA_MAP(DlgView)
	DDX_Text(pDX, IDC_EDIT1, GetDocument()->rectangle.left);
	DDX_Text(pDX, IDC_EDIT2, GetDocument()->rectangle.top);
	DDX_Text(pDX, IDC_EDIT3, GetDocument()->rectangle.right);
	DDX_Text(pDX, IDC_EDIT4, GetDocument()->rectangle.bottom);
	//}}AFX_DATA_MAP
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

void DlgView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) {
	UpdateData(false);
}

void DlgView::OnEnKillFocusEdit() {
	UpdateData(true);
	GetDocument()->UpdateAllViews(this);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// DlgView message handlers

