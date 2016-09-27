
// FTech_BaseDlg.h : header file
//

#pragma once

#include "PaneTitle.h"
#include "PaneView.h"
#include "PaneMenu.h"
#include "PaneStatus.h"

#include "FormAutoFocus.h"
#include "FormCamera.h"
#include "FormOptotune.h"
#include "FormSettings.h"

#include "include/CallbackThread.h"

// CFTech_BaseDlg dialog
class CFTech_BaseDlg : public CDialogEx
{
// Construction
public:
	CFTech_BaseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DIALOG_MAIN };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

public :
	CView* m_pTitle;	// ���ο��� �����ϱ� ������ 'delete'�� ȣ���ϸ� ������ ����. ���� Create()���� ������ �߻��ϸ� public���� �������̵� �ϸ� ��.
	CView* m_pView;
	CView* m_pControl;
	CView* m_pMenu;
	CView* m_pStatus;

	CView* m_pCamera;
	CView* m_pAutoFocus;
	CView* m_pOptotune;
	CView* m_pSetting;

	CCallbackThread	m_thdTime;

	void OnUpdateTime();
	void OnSwitchForm(int nMode);
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
};
