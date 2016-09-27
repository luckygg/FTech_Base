#pragma once

#include "resource.h"
//#include "include\ButtonEx.h"
//#include "include\LabelEx.h"
// CExitDlg dialog

class CExitDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CExitDlg)

public:
	CExitDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExitDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_EXIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public :
	bool IsSave() { return m_bSave; }

private :
	bool m_bSave;
	CLabelEx m_lbMsg;
	CLabelEx m_lbCaption;
	CButtonEx m_btnYes;
	CButtonEx m_btnNo;
	CButtonEx m_btnCancel;
	afx_msg void OnBnClickedExitBtnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedExitBtnYes();
	afx_msg void OnBnClickedExitBtnNo();
	
public:
	afx_msg void OnPaint();
	
};
