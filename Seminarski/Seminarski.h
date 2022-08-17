
// Seminarski.h : main header file for the Seminarski application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSeminarskiApp:
// See Seminarski.cpp for the implementation of this class
//

class CSeminarskiApp : public CWinApp
{
public:
	CSeminarskiApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSeminarskiApp theApp;
