#pragma once



// CFormSettings form view

class CFormSettings : public CFormView
{
	DECLARE_DYNCREATE(CFormSettings)

protected:
	CFormSettings();           // protected constructor used by dynamic creation
	virtual ~CFormSettings();

public:
	enum { IDD = IDD_FORM_SETTINGS };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnInitialUpdate();
};


