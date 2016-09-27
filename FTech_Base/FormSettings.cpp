// FormSettings.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_Base.h"
#include "FormSettings.h"


// CFormSettings

IMPLEMENT_DYNCREATE(CFormSettings, CFormView)

CFormSettings::CFormSettings()
	: CFormView(CFormSettings::IDD)
{

}

CFormSettings::~CFormSettings()
{
}

void CFormSettings::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormSettings, CFormView)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CFormSettings diagnostics

#ifdef _DEBUG
void CFormSettings::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormSettings::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormSettings message handlers


HBRUSH CFormSettings::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	HBRUSH hbr = CreateSolidBrush(COLOR_BKG_MAIN_DIALOG);

	return hbr;
}


void CFormSettings::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
}
