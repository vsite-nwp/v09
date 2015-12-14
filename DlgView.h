// DlgView.h : interface of the DlgView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGVIEW_H__57BAFF3B_DDEA_4CBF_80B7_8043FF50C394__INCLUDED_)
#define AFX_DLGVIEW_H__57BAFF3B_DDEA_4CBF_80B7_8043FF50C394__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class DlgView : public CFormView
{
protected: // create from serialization only
	DlgView();
	DECLARE_DYNCREATE(DlgView)

public:
	//{{AFX_DATA(DlgView)
	enum { IDD = IDD_V9_FORM };
	//}}AFX_DATA

// Attributes
public:
	Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~DlgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(DlgView)
/*** NWP V9 BEGIN ***/
	afx_msg void OnKillFocus();
/*** NWP V9 END ***/
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	int left;
	afx_msg void OnEnKillfocusEdit1();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // debug version in DlgView.cpp
inline Doc* DlgView::GetDocument()
   { return (Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGVIEW_H__57BAFF3B_DDEA_4CBF_80B7_8043FF50C394__INCLUDED_)
