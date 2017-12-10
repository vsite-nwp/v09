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
	ON_EN_CHANGE(IDC_EDIT1, &DlgView::OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &DlgView::OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &DlgView::OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT4, &DlgView::OnChangeEdit1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgView construction/destruction

DlgView::DlgView()
	: CFormView(DlgView::IDD)
	, left(_T(""))
	, top(_T(""))
	, right(_T(""))
	, bottom(_T(""))
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
	DDX_Text(pDX, IDC_EDIT1, GetDocument()->rec.left);
	DDX_Text(pDX, IDC_EDIT2, GetDocument()->rec.top);
	DDX_Text(pDX, IDC_EDIT3, GetDocument()->rec.right);
	DDX_Text(pDX, IDC_EDIT4, GetDocument()->rec.bottom);
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



void DlgView::OnChangeEdit1()
{
	try {
		UpdateData(true);
		GetDocument()->UpdateAllViews(this);
	}
	catch (...) {
	
	}
	
}


void DlgView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	UpdateData(false);
}


