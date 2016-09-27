#pragma once

// CPaneMenu form view
#define COLOR_BKG_TIMETABLE RGB(35,37,39)
//#include "include/LabelEx.h"
//#include "include/RadioEx.h"

class CPaneMenu : public CFormView
{
	DECLARE_DYNCREATE(CPaneMenu)

protected:
	CPaneMenu();           // protected constructor used by dynamic creation
	virtual ~CPaneMenu();

public :
	void OnUpdateTime();
public:
	enum { IDD = IDD_PANE_MENU };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CLabelEx m_lbTimeTable;
	CLabelEx m_lbYear;
	CLabelEx m_lbMonth;
	CLabelEx m_lbDay;
	CLabelEx m_lbTime;

	CRadioEx m_rbtnAutoFocus;
	CRadioEx m_rbtnCamera;
	CRadioEx m_rbtnOptotune;
	CRadioEx m_rbtnSettings;

	HBRUSH m_hbrBkg;

	virtual void OnInitialUpdate();
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedMenuRbtnAutofocus();
	afx_msg void OnBnClickedMenuRbtnCamera();
	afx_msg void OnBnClickedMenuRbtnOptotune();
	afx_msg void OnBnClickedMenuRbtnSettings();
};


