// FormOptotune.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_Base.h"
#include "FormOptotune.h"


// CFormOptotune

IMPLEMENT_DYNCREATE(CFormOptotune, CFormView)

CFormOptotune::CFormOptotune()
	: CFormView(CFormOptotune::IDD)
{

}

CFormOptotune::~CFormOptotune()
{
}

void CFormOptotune::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormOptotune, CFormView)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CFormOptotune diagnostics

#ifdef _DEBUG
void CFormOptotune::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormOptotune::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormOptotune message handlers


HBRUSH CFormOptotune::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	HBRUSH hbr = CreateSolidBrush(COLOR_BKG_MAIN_DIALOG);

	return hbr;
}


void CFormOptotune::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
}
