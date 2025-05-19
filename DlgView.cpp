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
	ON_EN_KILLFOCUS(IDC_EDIT1, OnEnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT2, OnEnKillfocusEdit2)
	ON_EN_KILLFOCUS(IDC_EDIT3, OnEnKillfocusEdit3)
	ON_EN_KILLFOCUS(IDC_EDIT4, OnEnKillfocusEdit4)
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
	//}}AFX_DATA_MAP

	// Povezujemo kontrole direktno s članovima dokumenta
	Doc* pDoc = GetDocument();
	DDX_Text(pDX, IDC_EDIT1, pDoc->m_rect.left);
	DDX_Text(pDX, IDC_EDIT2, pDoc->m_rect.top);
	DDX_Text(pDX, IDC_EDIT3, pDoc->m_rect.right);
	DDX_Text(pDX, IDC_EDIT4, pDoc->m_rect.bottom);
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

void DlgView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// Ažuriramo kontrole s podacima iz dokumenta
	UpdateData(FALSE);
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

void DlgView::OnEnKillfocusEdit1()
{
	UpdateData(TRUE);
	GetDocument()->UpdateAllViews(this);
	GetDocument()->SetModifiedFlag();
}

void DlgView::OnEnKillfocusEdit2()
{
	UpdateData(TRUE);
	GetDocument()->UpdateAllViews(this);
	GetDocument()->SetModifiedFlag();
}

void DlgView::OnEnKillfocusEdit3()
{
	UpdateData(TRUE);
	GetDocument()->UpdateAllViews(this);
	GetDocument()->SetModifiedFlag();
}

void DlgView::OnEnKillfocusEdit4()
{
	UpdateData(TRUE);
	GetDocument()->UpdateAllViews(this);
	GetDocument()->SetModifiedFlag();
}
