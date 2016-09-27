
// FTech_BaseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_Base.h"
#include "FTech_BaseDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFTech_BaseDlg dialog




CFTech_BaseDlg::CFTech_BaseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFTech_BaseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pTitle	= NULL;
	m_pView		= NULL;
	m_pControl	= NULL;
	m_pMenu		= NULL;
	m_pStatus	= NULL;

	m_pCamera	= NULL;
	m_pAutoFocus= NULL;
	m_pOptotune	= NULL;
	m_pSetting	= NULL;
}

void CFTech_BaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFTech_BaseDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CFTech_BaseDlg message handlers

BOOL CFTech_BaseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	this->MoveWindow(0,0,1920,1080);
	GetDlgItem(IDC_PANEL_TITLE	)->MoveWindow(   0,   0,1920, 130);
	GetDlgItem(IDC_PANEL_VIEW	)->MoveWindow(   0, 130, 900, 820);
	GetDlgItem(IDC_PANEL_CONTROL)->MoveWindow( 901, 131, 819, 819);
	//GetDlgItem(IDC_PANEL_CONTROL)->MoveWindow( 900, 130, 820, 820);
	GetDlgItem(IDC_PANEL_MENU	)->MoveWindow(1720, 130, 200, 820);
	GetDlgItem(IDC_PANEL_STATUS	)->MoveWindow(   0, 950,1920, 130);
	this->SetBackgroundColor( COLOR_BKG_MAIN_DIALOG, 0 ) ;

	CCreateContext context;
	ZeroMemory(&context, sizeof(context));
	CView* pView = NULL;
	CRect rect=CRect(0,0,0,0);
	
	//----- Pane Title -----//
	pView = (CView*)RUNTIME_CLASS(CPaneTitle)->CreateObject();
	GetDlgItem(IDC_PANEL_TITLE)->GetWindowRect(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_PANE_TITLE, &context);
	pView->OnInitialUpdate();
	m_pTitle = pView;

	m_pTitle->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PANEL_TITLE)->DestroyWindow();
	
	//----- Pane View -----//
	pView = (CView*)RUNTIME_CLASS(CPaneView)->CreateObject();
	GetDlgItem(IDC_PANEL_VIEW)->GetWindowRect(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_PANE_VIEW, &context);
	pView->OnInitialUpdate();
	m_pView = pView;

	m_pView->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PANEL_VIEW)->DestroyWindow();
	
	//----- Pane Control -----//
	pView = (CView*)RUNTIME_CLASS(CFormAutoFocus)->CreateObject();
	GetDlgItem(IDC_PANEL_CONTROL)->GetWindowRect(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDC_FORM_AUTOFOCUS, &context);
	pView->OnInitialUpdate();
	m_pAutoFocus = pView;

	pView = (CView*)RUNTIME_CLASS(CFormCamera)->CreateObject();
	GetDlgItem(IDC_PANEL_CONTROL)->GetWindowRect(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDC_FORM_CAMERA, &context);
	pView->OnInitialUpdate();
	m_pCamera = pView;

	pView = (CView*)RUNTIME_CLASS(CFormOptotune)->CreateObject();
	GetDlgItem(IDC_PANEL_CONTROL)->GetWindowRect(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDC_FORM_OPTOTUNE, &context);
	pView->OnInitialUpdate();
	m_pOptotune = pView;

	pView = (CView*)RUNTIME_CLASS(CFormSettings)->CreateObject();
	GetDlgItem(IDC_PANEL_CONTROL)->GetWindowRect(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDC_FORM_SETTING, &context);
	pView->OnInitialUpdate();
	m_pSetting = pView;

	m_pAutoFocus->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PANEL_CONTROL)->DestroyWindow();
	/*pView = (CView*)RUNTIME_CLASS(CPaneControl)->CreateObject();
	GetDlgItem(IDC_PANEL_CONTROL)->GetWindowRect(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_PANE_CONTROL, &context);
	pView->OnInitialUpdate();
	m_pControl = pView;

	m_pControl->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PANEL_CONTROL)->DestroyWindow();*/
	
	//----- Pane Menu -----//
	pView = (CView*)RUNTIME_CLASS(CPaneMenu)->CreateObject();
	GetDlgItem(IDC_PANEL_MENU)->GetWindowRect(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_PANE_MENU, &context);
	pView->OnInitialUpdate();
	m_pMenu = pView;

	m_pMenu->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PANEL_MENU)->DestroyWindow();
	
	//----- Pane Status -----//
	pView = (CView*)RUNTIME_CLASS(CPaneStatus)->CreateObject();
	GetDlgItem(IDC_PANEL_STATUS)->GetWindowRect(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_PANE_STATUS, &context);
	pView->OnInitialUpdate();
	m_pStatus = pView;

	m_pStatus->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PANEL_STATUS)->DestroyWindow();


	//----- Register Callback Thread -----//
	m_thdTime.RegisterCallback(this,&CFTech_BaseDlg::OnUpdateTime);
	m_thdTime.Start();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFTech_BaseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFTech_BaseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFTech_BaseDlg::OnUpdateTime()
{
	Sleep(30);
	CPaneMenu* pMenu = (CPaneMenu*)m_pMenu;
	pMenu->OnUpdateTime();
}

void CFTech_BaseDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_thdTime.IsDone() == false)
		m_thdTime.Stop();
}

void CFTech_BaseDlg::OnSwitchForm(int nMode)
{
	switch(nMode)
	{
	case FORM_AUTOFOCUS :
		m_pAutoFocus->ShowWindow(SW_SHOW);
		m_pCamera	->ShowWindow(SW_HIDE);
		m_pOptotune	->ShowWindow(SW_HIDE);
		m_pSetting	->ShowWindow(SW_HIDE);
		break;
	case FORM_CAMERA :
		m_pAutoFocus->ShowWindow(SW_HIDE);
		m_pCamera	->ShowWindow(SW_SHOW);
		m_pOptotune	->ShowWindow(SW_HIDE);
		m_pSetting	->ShowWindow(SW_HIDE);
		break;
	case FORM_OPTOTUNE :
		m_pAutoFocus->ShowWindow(SW_HIDE);
		m_pCamera	->ShowWindow(SW_HIDE);
		m_pOptotune	->ShowWindow(SW_SHOW);
		m_pSetting	->ShowWindow(SW_HIDE);
		break;
	case FORM_SETTINGS :
		m_pAutoFocus->ShowWindow(SW_HIDE);
		m_pCamera	->ShowWindow(SW_HIDE);
		m_pOptotune	->ShowWindow(SW_HIDE);
		m_pSetting	->ShowWindow(SW_SHOW);
		break;
	}
}