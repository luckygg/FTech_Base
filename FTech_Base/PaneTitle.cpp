// PaneTitle.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_Base.h"
#include "PaneTitle.h"
#include "ExitDlg.h"

// CPaneTitle

IMPLEMENT_DYNCREATE(CPaneTitle, CFormView)

CPaneTitle::CPaneTitle()
	: CFormView(CPaneTitle::IDD)
{

}

CPaneTitle::~CPaneTitle()
{
}

void CPaneTitle::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TITLE_LB_LOGO, m_LbLogo);
	DDX_Control(pDX, IDC_TITLE_BTN_EXIT, m_btnExit);
	DDX_Control(pDX, IDC_TITLE_BTN_MINI, m_btnMini);
}

BEGIN_MESSAGE_MAP(CPaneTitle, CFormView)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_TITLE_BTN_MINI, &CPaneTitle::OnBnClickedTitleBtnMini)
	ON_BN_CLICKED(IDC_TITLE_BTN_EXIT, &CPaneTitle::OnBnClickedTitleBtnExit)
END_MESSAGE_MAP()


// CPaneTitle diagnostics

#ifdef _DEBUG
void CPaneTitle::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPaneTitle::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPaneTitle message handlers

HBRUSH CPaneTitle::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return m_hbrBkg;
}


void CPaneTitle::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	m_hbrBkg = CreateSolidBrush(COLOR_BKG_MAIN_DIALOG);

	CRect rect;
	GetClientRect(&rect);

	//----- Logo -----//
	m_LbLogo.LoadImageFromResource(IDB_PNG_LOGO,true);
	int r = GetRValue(COLOR_BKG_MAIN_DIALOG);
	int g = GetGValue(COLOR_BKG_MAIN_DIALOG);
	int b = GetBValue(COLOR_BKG_MAIN_DIALOG);
	m_LbLogo.SetColorBkg(255,r,g,b);
	m_LbLogo.SetColorBorder(255,r,g,b);
	//----- Button Minimize -----//
	m_btnMini.LoadImageFromResource(IDB_BMP_MINI,false);
	m_btnMini.MoveWindow(1820,0,50,50);
	m_btnMini.SetSizeBorder(0);
	m_btnMini.SetSizeImage(12,12,25,25);
	m_btnMini.SetColorBkg(255,r,g,b);
	m_btnMini.SetColorBorder(255,r,g,b);
	//----- Button Exit -----//
	m_btnExit.LoadImageFromResource(IDB_BMP_EXIT,false);
	m_btnExit.MoveWindow(1870,0,50,50);
	m_btnExit.SetSizeBorder(0);
	m_btnExit.SetSizeImage(12,12,25,25);
	m_btnExit.SetColorBkg(255,r,g,b);
	m_btnExit.SetColorBorder(255,r,g,b);
}


void CPaneTitle::OnBnClickedTitleBtnMini()
{
	GetParent()->ShowWindow(SW_MINIMIZE);
}


void CPaneTitle::OnBnClickedTitleBtnExit()
{
	CExitDlg dlg;
	INT_PTR ret = dlg.DoModal();
	if (ret == IDOK)
	{
		if (dlg.IsSave())
		{
			//AfxMessageBox(L"SAVE!");
		}
		else
		{
			//AfxMessageBox(L"No Save!");
		}
		
		GetParent()->DestroyWindow();
	}
	else if (ret == IDCANCEL)
	{

	}

}
