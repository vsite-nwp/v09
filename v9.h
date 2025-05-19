// v9.h : main header file for the V9 application
//

#if !defined(AFX_V9_H__7AADCB76_4C9A_4B9B_9A5A_9F1D2C3D4E5F__INCLUDED_)
#define AFX_V9_H__7AADCB76_4C9A_4B9B_9A5A_9F1D2C3D4E5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// App:
// See v9.cpp for the implementation of this class
//

class App : public CWinApp
{
public:
	App();

	// Overrides
		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(App)
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(App)
	afx_msg void OnAppAbout();
	afx_msg void OnNewPaintView();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CMultiDocTemplate* paintTmpl;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_V9_H__7AADCB76_4C9A_4B9B_9A5A_9F1D2C3D4E5F__INCLUDED_)
