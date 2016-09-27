#pragma once



// CPaneStatus form view

class CPaneStatus : public CFormView
{
	DECLARE_DYNCREATE(CPaneStatus)

protected:
	CPaneStatus();           // protected constructor used by dynamic creation
	virtual ~CPaneStatus();

public:
	enum { IDD = IDD_PANE_STATUS };
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


