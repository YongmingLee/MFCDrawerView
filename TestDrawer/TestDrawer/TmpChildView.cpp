// TmpChildView.cpp : implementation file
//

#include "stdafx.h"
#include "TestDrawer.h"
#include "TmpChildView.h"


// CTmpChildView

IMPLEMENT_DYNAMIC(CTmpChildView, CWnd)

CTmpChildView::CTmpChildView()
{

}

CTmpChildView::~CTmpChildView()
{
}


BEGIN_MESSAGE_MAP(CTmpChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CTmpChildView message handlers




void CTmpChildView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CWnd::OnPaint() for painting messages
	CRect rect;
	GetClientRect(&rect);
	dc.FillSolidRect(&rect, RGB(128,64,64));
}
