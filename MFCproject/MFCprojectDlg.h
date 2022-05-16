
// MFCprojectDlg.h : header file
//

#pragma once

#include "Figure.h"
//!! 17 b
#include "RectangleF.h"
#include "EllipseF.h"
#include "SegmentF.h"
//!! 17 e

// CMFCprojectDlg dialog
class CMFCprojectDlg : public CDialogEx
{
private:
	CToolBar m_ToolBar;
	COLORREF outsideColor;// מחליט איזה צבע יהיה 
	COLORREF insideColor;// מחליט איזה צבע יהיה 
	CMFCColorButton outside_Color; //לוקח צבע מהכפתור 
	CMFCColorButton inside_Color;

	int m_PenWidth;

// Construction
public:
	CMFCprojectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	CPoint start, end;
	bool isPressed=false;
	 CTypedPtrArray< CObArray, Figure*> figs;
	 CTypedPtrArray< CObArray, Figure*> temp;

 
	 int futureFigureKind = 1; //Rectangle (2 - Ellipse)
	 
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnChooseUndo();
	afx_msg void ToDo();
	afx_msg void Ellipse();
	afx_msg void Retangle();
	afx_msg void Pencil();
	afx_msg void newPage();
	afx_msg void ChooseSave();
	afx_msg void ChooseLoad();
	afx_msg void OnFileSave32797();
	afx_msg void OnFileLoad();
	afx_msg void OnPenwidthSmall();
	afx_msg void OnPenwidthLarge();
	afx_msg void OnPenwidthMedium();
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnBnClickedMfccolorbutton2();
	afx_msg void EmptyRetangle();
	afx_msg void EmptyEllipse();
	afx_msg void OnFileExit();
	afx_msg void OnBnClickedOk();
	afx_msg void DecreaseThin();
	afx_msg void IncreaseThin();

	
};
