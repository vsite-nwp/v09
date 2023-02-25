#pragma once

#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// App:
// See v9.cpp for the implementation of this class
//

class App : public CWinApp
{
	CMultiDocTemplate* paintTmpl;
public:
	App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(App)
	afx_msg void OnAppAbout();
	afx_msg void OnNewPaintView();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
