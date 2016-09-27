// FormAutoFocus.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_Base.h"
#include "FormAutoFocus.h"


// CFormAutoFocus

IMPLEMENT_DYNCREATE(CFormAutoFocus, CFormView)

CFormAutoFocus::CFormAutoFocus()
	: CFormView(CFormAutoFocus::IDD)
{

}

CFormAutoFocus::~CFormAutoFocus()
{
}

void CFormAutoFocus::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormAutoFocus, CFormView)
	ON_WM_CTLCOLOR()
//	ON_WM_PAINT()
END_MESSAGE_MAP()


// CFormAutoFocus diagnostics

#ifdef _DEBUG
void CFormAutoFocus::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormAutoFocus::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormAutoFocus message handlers


void CFormAutoFocus::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	m_hbrBkg = CreateSolidBrush(COLOR_BKG_MAIN_DIALOG);
}


HBRUSH CFormAutoFocus::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return m_hbrBkg;
}