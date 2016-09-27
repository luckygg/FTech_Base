// FormCamera.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_Base.h"
#include "FormCamera.h"


// CFormCamera

IMPLEMENT_DYNCREATE(CFormCamera, CFormView)

CFormCamera::CFormCamera()
	: CFormView(CFormCamera::IDD)
{

}

CFormCamera::~CFormCamera()
{
}

void CFormCamera::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormCamera, CFormView)
	ON_WM_CTLCOLOR()
//	ON_WM_PAINT()
END_MESSAGE_MAP()


// CFormCamera diagnostics

#ifdef _DEBUG
void CFormCamera::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormCamera::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormCamera message handlers


HBRUSH CFormCamera::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return m_hbrBkg;
}


void CFormCamera::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	m_hbrBkg = CreateSolidBrush(COLOR_BKG_MAIN_DIALOG);
}
