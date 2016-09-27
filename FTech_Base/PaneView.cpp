// PaneView.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_Base.h"
#include "PaneView.h"


// CPaneView

IMPLEMENT_DYNCREATE(CPaneView, CFormView)

CPaneView::CPaneView()
	: CFormView(CPaneView::IDD)
{

}

CPaneView::~CPaneView()
{
}

void CPaneView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VIEW_CS_DISPLAY, m_viewDisplay);
}

BEGIN_MESSAGE_MAP(CPaneView, CFormView)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CPaneView diagnostics

#ifdef _DEBUG
void CPaneView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPaneView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPaneView message handlers


HBRUSH CPaneView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return m_hbrBkg;
}


void CPaneView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	m_hbrBkg = CreateSolidBrush(COLOR_BKG_MAIN_DIALOG);

	CRect rect;
	GetClientRect(&rect);
	m_viewDisplay.InitControl(this);
	m_viewDisplay.MoveWindow(10,10,rect.Width()-20,rect.Height()-20);
}
