// PaneMenu.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_Base.h"
#include "FTech_BaseDlg.h"
#include "PaneMenu.h"


// CPaneMenu

IMPLEMENT_DYNCREATE(CPaneMenu, CFormView)

CPaneMenu::CPaneMenu()
	: CFormView(CPaneMenu::IDD)
{

}

CPaneMenu::~CPaneMenu()
{
}

void CPaneMenu::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MENU_LB_TIMETABLE, m_lbTimeTable);
	DDX_Control(pDX, IDC_MENU_LB_YEAR, m_lbYear);
	DDX_Control(pDX, IDC_MENU_LB_MONTH, m_lbMonth);
	DDX_Control(pDX, IDC_MENU_LB_DAY, m_lbDay);
	DDX_Control(pDX, IDC_MENU_LB_TIME, m_lbTime);
	DDX_Control(pDX, IDC_MENU_RBTN_AUTOFOCUS, m_rbtnAutoFocus);
	DDX_Control(pDX, IDC_MENU_RBTN_CAMERA, m_rbtnCamera);
	DDX_Control(pDX, IDC_MENU_RBTN_OPTOTUNE, m_rbtnOptotune);
	DDX_Control(pDX, IDC_MENU_RBTN_SETTINGS, m_rbtnSettings);
}

BEGIN_MESSAGE_MAP(CPaneMenu, CFormView)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_MENU_RBTN_AUTOFOCUS, &CPaneMenu::OnBnClickedMenuRbtnAutofocus)
	ON_BN_CLICKED(IDC_MENU_RBTN_CAMERA, &CPaneMenu::OnBnClickedMenuRbtnCamera)
	ON_BN_CLICKED(IDC_MENU_RBTN_OPTOTUNE, &CPaneMenu::OnBnClickedMenuRbtnOptotune)
	ON_BN_CLICKED(IDC_MENU_RBTN_SETTINGS, &CPaneMenu::OnBnClickedMenuRbtnSettings)
END_MESSAGE_MAP()


// CPaneMenu diagnostics

#ifdef _DEBUG
void CPaneMenu::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPaneMenu::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPaneMenu message handlers


HBRUSH CPaneMenu::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return m_hbrBkg;
}


void CPaneMenu::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	m_hbrBkg = CreateSolidBrush(COLOR_BKG_MAIN_DIALOG);

	CRect rect;
	GetClientRect(&rect);

	m_lbTimeTable.LoadImageFromResource(IDB_PNG_TIME,true);
	m_lbTimeTable.MoveWindow(0,0,200,200);
	m_lbTimeTable.SetSizeImage(0,0,200,200);

	int r = GetRValue(COLOR_BKG_MAIN_DIALOG);
	int g = GetGValue(COLOR_BKG_MAIN_DIALOG);
	int b = GetBValue(COLOR_BKG_MAIN_DIALOG);
	m_lbTimeTable.SetColorBkg(255,r,g,b);
	m_lbTimeTable.SetColorBorder(255,r,g,b);

	r = GetRValue(COLOR_BKG_TIMETABLE);
	g = GetGValue(COLOR_BKG_TIMETABLE);
	b = GetBValue(COLOR_BKG_TIMETABLE);
	m_lbYear.SetColorBkg(255,r,g,b);
	m_lbYear.SetColorBorder(255,r,g,b);
	m_lbYear.MoveWindow(140,46,60,20);

	m_lbMonth.SetColorBkg(255,r,g,b);
	m_lbMonth.SetColorBorder(255,r,g,b);
	m_lbMonth.MoveWindow(84,46,35,20);

	m_lbDay.SetColorBkg(255,r,g,b);
	m_lbDay.SetColorBorder(255,r,g,b);
	m_lbDay.MoveWindow(19,46,35,20);

	m_lbTime.SetSizeText(40);
	m_lbTime.SetColorBkg(255,r,g,b);
	m_lbTime.SetColorBorder(255,r,g,b);
	m_lbTime.MoveWindow(5,115,191,78);

	m_rbtnAutoFocus.MoveWindow(0,300,200,80);
	m_rbtnAutoFocus.LoadImageFromResource(IDB_PNG_CHK_AUTOFOCUS,IDB_PNG_NOM_AUTOFOCUS,true);
	m_rbtnAutoFocus.SetCheck(1);
	m_rbtnAutoFocus.SetGroupBegin();

	m_rbtnCamera.MoveWindow(0,382,200,80);
	m_rbtnCamera.LoadImageFromResource(IDB_PNG_CHK_CAMERA,IDB_PNG_NOM_CAMERA,true);

	m_rbtnOptotune.MoveWindow(0,464,200,80);
	m_rbtnOptotune.LoadImageFromResource(IDB_PNG_CHK_OPTOTUNE,IDB_PNG_NOM_OPTOTUNE,true);

	m_rbtnSettings.MoveWindow(0,546,200,80);
	m_rbtnSettings.LoadImageFromResource(IDB_PNG_CHK_SETTINGS,IDB_PNG_NOM_SETTINGS,true);
	m_rbtnSettings.SetGroupEnd();
	
}

void CPaneMenu::OnUpdateTime()
{
	CTime time;
	time = CTime::GetCurrentTime();

	CString strYear=L"";
	strYear.Format(L"%d",time.GetYear());
	CString strMonth=L"";
	strMonth.Format(L"%d",time.GetMonth());
	CString strDay=L"";
	strDay.Format(L"%d",time.GetDay());

	CString strTime=L"";
	strTime.Format(L"%02d:%02d:%02d",time.GetHour(),time.GetMinute(),time.GetSecond());

	m_lbYear.SetText(strYear);
	m_lbMonth.SetText(strMonth);
	m_lbDay.SetText(strDay);
	m_lbTime.SetText(strTime);
}

void CPaneMenu::OnPaint()
{
	CPaintDC dc(this);
	
	Graphics mainG (dc.GetSafeHdc());
	Pen pen(Color(255,240,240,240),1);

	mainG.DrawLine(&pen, Point(28,381), Point(180,381));
	mainG.DrawLine(&pen, Point(28,463), Point(180,463));
	mainG.DrawLine(&pen, Point(28,545), Point(180,545));
}


void CPaneMenu::OnBnClickedMenuRbtnAutofocus()
{
	CFTech_BaseDlg *pMain = (CFTech_BaseDlg *)GetParent();
	pMain->OnSwitchForm(FORM_AUTOFOCUS);
}


void CPaneMenu::OnBnClickedMenuRbtnCamera()
{
	CFTech_BaseDlg *pMain = (CFTech_BaseDlg *)GetParent();
	pMain->OnSwitchForm(FORM_CAMERA);
}


void CPaneMenu::OnBnClickedMenuRbtnOptotune()
{
	CFTech_BaseDlg *pMain = (CFTech_BaseDlg *)GetParent();
	pMain->OnSwitchForm(FORM_OPTOTUNE);
}


void CPaneMenu::OnBnClickedMenuRbtnSettings()
{
	CFTech_BaseDlg *pMain = (CFTech_BaseDlg *)GetParent();
	pMain->OnSwitchForm(FORM_SETTINGS);
}
