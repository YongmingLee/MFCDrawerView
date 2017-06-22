#pragma once


// CTmpChildView

class CTmpChildView : public CWnd
{
	DECLARE_DYNAMIC(CTmpChildView)

public:
	CTmpChildView();
	virtual ~CTmpChildView();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


