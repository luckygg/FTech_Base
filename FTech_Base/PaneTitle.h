#pragma once

#include "resource.h"
//#include "include/LabelEx.h"
//#include "include/ButtonEx.h"

// CPaneTitle form view

class CPaneTitle : public CFormView
{
	DECLARE_DYNCREATE(CPaneTitle)

protected:
	CPaneTitle();           // protected constructor used by dynamic creation
	virtual ~CPaneTitle();

public:
	enum { IDD = IDD_PANE_TITLE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
private :
	HBRUSH m_hbrBkg;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	virtual void OnInitialUpdate();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CLabelEx m_LbLogo;
	virtual void OnInitialUpdate();
	CButtonEx m_btnExit;
	CButtonEx m_btnMini;
	afx_msg void OnBnClickedTitleBtnMini();
	afx_msg void OnBnClickedTitleBtnExit();
};


