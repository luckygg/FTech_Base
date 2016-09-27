#pragma once



// CFormCamera form view

class CFormCamera : public CFormView
{
	DECLARE_DYNCREATE(CFormCamera)

protected:
	CFormCamera();           // protected constructor used by dynamic creation
	virtual ~CFormCamera();

public:
	enum { IDD = IDD_FORM_CAMERA };
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
	virtual void OnInitialUpdate();

};


