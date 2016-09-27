// PaneStatus.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_Base.h"
#include "PaneStatus.h"


// CPaneStatus

IMPLEMENT_DYNCREATE(CPaneStatus, CFormView)

CPaneStatus::CPaneStatus()
	: CFormView(CPaneStatus::IDD)
{

}

CPaneStatus::~CPaneStatus()
{
}

void CPaneStatus::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPaneStatus, CFormView)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CPaneStatus diagnostics

#ifdef _DEBUG
void CPaneStatus::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPaneStatus::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPaneStatus message handlers


HBRUSH CPaneStatus::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return m_hbrBkg;
}


void CPaneStatus::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	m_hbrBkg = CreateSolidBrush(COLOR_BKG_MAIN_DIALOG);
}
