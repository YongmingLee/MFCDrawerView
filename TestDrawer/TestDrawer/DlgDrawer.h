#pragma once


// CDlgDrawer dialog
#include "TmpChildView.h"

class CDlgDrawer : public CDialog
{
	DECLARE_DYNAMIC(CDlgDrawer)

public:
	CDlgDrawer(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgDrawer();

// Dialog Data
	enum { IDD = IDD_DLG_DRAWER };

	static void CreateStatic(CWnd* parent, RECT& rect);

protected:

	CArray<CButton*> m_buttonArray;
	CButton* m_pFocusedButton;
	CRect m_singleButtonRect;
	CTmpChildView* m_pChildView;

	void FocusButton(CButton* pButton);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_btn1;
	CButton m_btn2;
	CButton m_btn3;
	CButton m_btn4;
	CButton m_btn5;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClickedBtn1();
	afx_msg void OnClickedBtn2();
	afx_msg void OnClickedBtn3();
	afx_msg void OnClickedBtn4();
	afx_msg void OnClickedBtn5();
};
