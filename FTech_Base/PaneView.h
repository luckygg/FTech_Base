#pragma once

// CPaneView form view
//#include "include/ViewerEx.h"
class CPaneView : public CFormView
{
	DECLARE_DYNCREATE(CPaneView)

protected:
	CPaneView();           // protected constructor used by dynamic creation
	virtual ~CPaneView();

public:
	enum { IDD = IDD_PANE_VIEW };
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
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CViewerEx m_viewDisplay;
	virtual void OnInitialUpdate();
};


