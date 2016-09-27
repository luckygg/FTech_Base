
// FTech_Base.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

#include "include/LabelEx.h"
#include "include/ButtonEx.h"
#include "include/RadioEx.h"
#include "include/ViewerEx.h"

#define COLOR_BKG_MAIN_DIALOG	RGB( 45, 47, 49)
#define COLOR_BKG_EXIT_DIALOG	RGB( 45, 47, 49)
#define COLOR_BKG_GROUP			RGB( 45, 47, 49)
#define COLOR_BORDER			RGB( 39,108, 79)
#define COLOR_BORDER_DIALOG		RGB( 34,168,108)
#define COLOR_BKG_BTN_OK		RGB( 34,168,108)
#define COLOR_BKG_BTN_NG		RGB(220, 81, 58)
#define COLOR_TEXT				RGB(255,255,255)

#define IDC_FORM_AUTOFOCUS	WM_USER+0
#define IDC_FORM_CAMERA		WM_USER+1
#define IDC_FORM_OPTOTUNE	WM_USER+2
#define IDC_FORM_SETTING	WM_USER+3

enum { FORM_AUTOFOCUS=0, FORM_CAMERA, FORM_OPTOTUNE, FORM_SETTINGS };
// CFTech_BaseApp:
// See FTech_Base.cpp for the implementation of this class
//

class CFTech_BaseApp : public CWinApp
{
public:
	CFTech_BaseApp();

	ULONG_PTR m_gdiplusToken;
// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFTech_BaseApp theApp;