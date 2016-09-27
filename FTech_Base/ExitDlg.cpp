// ExitDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_Base.h"
#include "ExitDlg.h"
#include "afxdialogex.h"


// CExitDlg dialog

IMPLEMENT_DYNAMIC(CExitDlg, CDialogEx)

CExitDlg::CExitDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExitDlg::IDD, pParent)
{
	m_bSave = false;
}

CExitDlg::~CExitDlg()
{
}

void CExitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXIT_BTN_CANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_EXIT_BTN_YES, m_btnYes);
	DDX_Control(pDX, IDC_EXIT_BTN_NO, m_btnNo);
	DDX_Control(pDX, IDC_EXIT_LB_MESSAGE, m_lbMsg);
	DDX_Control(pDX, IDC_EXIT_LB_CAPTION, m_lbCaption);
}


BEGIN_MESSAGE_MAP(CExitDlg, CDialogEx)
	ON_BN_CLICKED(IDC_EXIT_BTN_CANCEL, &CExitDlg::OnBnClickedExitBtnCancel)
	ON_BN_CLICKED(IDC_EXIT_BTN_YES, &CExitDlg::OnBnClickedExitBtnYes)
	ON_BN_CLICKED(IDC_EXIT_BTN_NO, &CExitDlg::OnBnClickedExitBtnNo)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CExitDlg message handlers

BOOL CExitDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	this->SetBackgroundColor( COLOR_BKG_EXIT_DIALOG, 0 ) ;
	int r = GetRValue(COLOR_BKG_EXIT_DIALOG);
	int g = GetGValue(COLOR_BKG_EXIT_DIALOG);
	int b = GetBValue(COLOR_BKG_EXIT_DIALOG);

	m_lbMsg.SetColorBkg(255,r,g,b);
	m_lbMsg.SetColorBorder(255,r,g,b);
	m_lbMsg.SetText(L"저장하고 종료하시겠습니까?");
	m_lbMsg.SetAlignTextCM();
	m_lbMsg.SetSizeText(25);

	r = GetRValue(COLOR_BKG_BTN_OK);
	g = GetGValue(COLOR_BKG_BTN_OK);
	b = GetBValue(COLOR_BKG_BTN_OK);
	m_btnYes.SetColorBkg(255,r,g,b);
	m_btnYes.SetColorBorder(255,r,g,b);
	m_btnYes.SetText(L"YES");
	m_btnYes.SetAlignTextCM();

	m_btnNo.SetColorBkg(255,r,g,b);
	m_btnNo.SetColorBorder(255,r,g,b);
	m_btnNo.SetText(L"NO");
	m_btnNo.SetAlignTextCM();

	r = GetRValue(COLOR_BKG_BTN_NG);
	g = GetGValue(COLOR_BKG_BTN_NG);
	b = GetBValue(COLOR_BKG_BTN_NG);
	m_btnCancel.SetColorBkg(255,r,g,b);
	m_btnCancel.SetColorBorder(255,r,g,b);
	m_btnCancel.SetText(L"CANCEL");
	m_btnCancel.SetAlignTextCM();

	CRect rect;
	GetClientRect(&rect);
	m_lbCaption.MoveWindow(1,1,rect.Width()-2, 50);
	m_lbCaption.SetColorBkg(255,42,42,43);
	m_lbCaption.SetColorBorder(255,42,42,43);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CExitDlg::OnBnClickedExitBtnYes()
{
	m_bSave = true;
	OnOK();
}


void CExitDlg::OnBnClickedExitBtnNo()
{
	m_bSave = false;
	OnOK();
}

void CExitDlg::OnBnClickedExitBtnCancel()
{
	OnCancel();
}

void CExitDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	CRect rect;
	GetClientRect(&rect);
	
	Graphics mainG (dc.GetSafeHdc());
	int r = GetRValue(COLOR_BORDER_DIALOG);
	int g = GetGValue(COLOR_BORDER_DIALOG);
	int b = GetBValue(COLOR_BORDER_DIALOG);

	Pen pen(Color(255,r,g,b),2);
	mainG.DrawRectangle(&pen,rect.left,rect.top,rect.Width(),rect.Height());
}
