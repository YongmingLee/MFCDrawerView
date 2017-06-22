// DlgDrawer.cpp : implementation file
//

#include "stdafx.h"
#include "TestDrawer.h"
#include "DlgDrawer.h"
#include "afxdialogex.h"


// CDlgDrawer dialog

IMPLEMENT_DYNAMIC(CDlgDrawer, CDialog)

CDlgDrawer::CDlgDrawer(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDrawer::IDD, pParent)
{
	m_pFocusedButton = NULL;
}

CDlgDrawer::~CDlgDrawer()
{
}

void CDlgDrawer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN1, m_btn1);
	DDX_Control(pDX, IDC_BTN2, m_btn2);
	DDX_Control(pDX, IDC_BTN3, m_btn3);
	DDX_Control(pDX, IDC_BTN4, m_btn4);
	DDX_Control(pDX, IDC_BTN5, m_btn5);
}


BEGIN_MESSAGE_MAP(CDlgDrawer, CDialog)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTN1, &CDlgDrawer::OnClickedBtn1)
	ON_BN_CLICKED(IDC_BTN2, &CDlgDrawer::OnClickedBtn2)
	ON_BN_CLICKED(IDC_BTN3, &CDlgDrawer::OnClickedBtn3)
	ON_BN_CLICKED(IDC_BTN4, &CDlgDrawer::OnClickedBtn4)
	ON_BN_CLICKED(IDC_BTN5, &CDlgDrawer::OnClickedBtn5)
END_MESSAGE_MAP()


// CDlgDrawer message handlers


BOOL CDlgDrawer::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	m_pChildView = new CTmpChildView;
	RECT rect;
	m_pChildView->Create(NULL,NULL,WS_CHILD|WS_VISIBLE,rect,this,1234);
	m_pChildView->ShowWindow(SW_SHOW);

	m_buttonArray.Add(&m_btn1);
	m_buttonArray.Add(&m_btn2);
	m_buttonArray.Add(&m_btn3);
	m_buttonArray.Add(&m_btn4);
	m_buttonArray.Add(&m_btn5);

	m_btn1.GetClientRect(&m_singleButtonRect);

	FocusButton(&m_btn1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgDrawer::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	if (m_pFocusedButton) {
		FocusButton(m_pFocusedButton);
	}
}

void CDlgDrawer::CreateStatic(CWnd* parent, RECT& rect)
{
	CDlgDrawer* pDlg = new CDlgDrawer();
	pDlg->Create(IDD_DLG_DRAWER, parent);
	pDlg->ShowWindow(SW_SHOW);
	pDlg->MoveWindow(&rect);
}

void CDlgDrawer::OnClickedBtn1()
{
	FocusButton(&m_btn1);
}


void CDlgDrawer::OnClickedBtn2()
{
	FocusButton(&m_btn2);
}


void CDlgDrawer::OnClickedBtn3()
{
	FocusButton(&m_btn3);
}


void CDlgDrawer::OnClickedBtn4()
{
	FocusButton(&m_btn4);
}


void CDlgDrawer::OnClickedBtn5()
{
	FocusButton(&m_btn5);
}

void CDlgDrawer::FocusButton(CButton* pButton)
{
	m_pFocusedButton = pButton;
	
	BOOL isUp = TRUE;
	CRect clientRect;
	GetClientRect(&clientRect);
	int height = m_singleButtonRect.Height();
	int width = clientRect.Width();
	int heightToBeAdded = clientRect.Height() - 5*height;
	CRect lastButtonRect;
	lastButtonRect.SetRectEmpty();

	for (int i = 0; i < m_buttonArray.GetCount(); i ++) {

		CButton* pCur = m_buttonArray.ElementAt(i);
		CRect buttonRect;

		if (!isUp) {

			buttonRect.top = lastButtonRect.bottom + heightToBeAdded;
			heightToBeAdded = 0;

		} else {

			buttonRect.top = lastButtonRect.bottom;

			if (pButton == pCur) {
				isUp = FALSE;

				if (heightToBeAdded > 0) {

					CRect rectChildView;
					rectChildView.left = 0;
					rectChildView.right = width;
					rectChildView.top = buttonRect.top + height;
					rectChildView.bottom = rectChildView.top + heightToBeAdded;
					m_pChildView->MoveWindow(&rectChildView);
				}
			}
		}

		buttonRect.left = 0;
		buttonRect.right = width;
		buttonRect.bottom = buttonRect.top + height;
		pCur->MoveWindow(&buttonRect);

		lastButtonRect.CopyRect(&buttonRect);
	}

	m_pChildView->Invalidate();
}