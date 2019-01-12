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
	ON_EN_KILLFOCUS(IDC_EDIT1, &DlgView::OnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT2, &DlgView::OnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT3, &DlgView::OnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT4, &DlgView::OnKillfocusEdit1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgView construction/destruction

DlgView::DlgView()
	: CFormView(DlgView::IDD)
	, left(0)
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
	DDX_Text(pDX, IDC_EDIT1, GetDocument()->elipsa.left); 
	DDX_Text(pDX, IDC_EDIT2, GetDocument()->elipsa.top);
	DDX_Text(pDX, IDC_EDIT3, GetDocument()->elipsa.right);
	DDX_Text(pDX, IDC_EDIT4, GetDocument()->elipsa.bottom);
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



void DlgView::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}





void DlgView::OnKillfocusEdit1()
{
	UpdateData(true);
	this->GetDocument()->UpdateAllViews(this);
}

void DlgView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	UpdateData(false);
}
