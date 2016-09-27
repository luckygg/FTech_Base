#pragma once



// CFormAutoFocus form view

class CFormAutoFocus : public CFormView
{
	DECLARE_DYNCREATE(CFormAutoFocus)

protected:
	CFormAutoFocus();           // protected constructor used by dynamic creation
	virtual ~CFormAutoFocus();

public:
	enum { IDD = IDD_FORM_AUTOFOCUS };
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
	virtual void OnInitialUpdate();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

};


