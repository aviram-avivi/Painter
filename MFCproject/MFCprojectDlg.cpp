
// MFCprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/): CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	outsideColor = RGB(0, 0, 0); //???? ?? ???? ????? 
	insideColor = RGB(255,255,255);// ???? ?? ???? ????
	m_PenWidth = 2;// ???? ?? ????? ????
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, outside_Color);// ???? ?? ???? ?????? ????? ????? ??????
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, inside_Color);
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()

	//Buttons
	ON_BN_CLICKED(IDOK, &CMFCprojectDlg::OnBnClickedOk)

	// Tools Bar
	ON_COMMAND(ID_Choose_Save, &CMFCprojectDlg::ChooseSave) 
	ON_COMMAND(ID_Choose_Load, &CMFCprojectDlg::ChooseLoad) 
	ON_COMMAND(ID_Choose_Undo, &CMFCprojectDlg::OnChooseUndo) 
	ON_COMMAND(ID_To_Do, &CMFCprojectDlg::ToDo)
	ON_COMMAND(ID_Ellipse, &CMFCprojectDlg::Ellipse)
	ON_COMMAND(ID_Retangle, &CMFCprojectDlg::Retangle)
	ON_COMMAND(ID_Pencil, &CMFCprojectDlg::Pencil)
	ON_COMMAND(ID_newPage, &CMFCprojectDlg::newPage)
	ON_COMMAND(ID_IncreaseThin, &CMFCprojectDlg::IncreaseThin)
	ON_COMMAND(ID_DecreaseThin, &CMFCprojectDlg::DecreaseThin)
	// Menu
	ON_COMMAND(ID_FILE_SAVE32797, &CMFCprojectDlg::OnFileSave32797)
	ON_COMMAND(ID_FILE_LOAD, &CMFCprojectDlg::OnFileLoad)
	ON_COMMAND(ID_PENWIDTH_SMALL, &CMFCprojectDlg::OnPenwidthSmall)
	ON_COMMAND(ID_PENWIDTH_LARGE, &CMFCprojectDlg::OnPenwidthLarge)
	ON_COMMAND(ID_PENWIDTH_M, &CMFCprojectDlg::OnPenwidthMedium)
	ON_COMMAND(ID_FILE_EXIT, &CMFCprojectDlg::OnFileExit)

	// Select Color Button
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CMFCprojectDlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CMFCprojectDlg::OnBnClickedMfccolorbutton2)

	



END_MESSAGE_MAP()


// CMFCprojectDlg message handlers

BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Tools Bar
	if (!m_ToolBar.CreateEx(this, TBSTYLE_FLAT,WS_VISIBLE | CBRS_TOP | CBRS_TOOLTIPS |CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||!m_ToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		EndDialog(IDCANCEL);
	}
	m_ToolBar.EnableToolTips(true);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CMFCprojectDlg::OnPaint()
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
		CRect rect;
		GetClientRect(&rect);
		CPaintDC dc(this);
		for (int i = 0; i < figs.GetSize(); i++)
			figs[i]->Draw(&dc);
		CDialogEx::OnPaint();

		CString opening("PaintIt");
		rect.OffsetRect(-330, 220);
		dc.SetTextColor(RGB(255, 0, 0));
		dc.DrawText(opening, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);


	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	start = point;
	isPressed = true;
	switch (futureFigureKind)
	{
	case 1:
		figs.Add(new RectangleF(start, start, m_PenWidth,outsideColor, insideColor));
		break;
	case 2:
  	    figs.Add(new EllipseF(start, start, m_PenWidth,outsideColor, insideColor));
		break;
	case 3:
		figs.Add(new SegmentF(start, start, m_PenWidth,outsideColor));
		break;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	if (isPressed)
	{
		end = point;
		isPressed = false;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		end = point;
		figs[figs.GetSize()-1]->Redefine(start,end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnMouseMove(nFlags, point);
}




void CMFCprojectDlg::OnChooseUndo()
{
	if (figs.GetSize() != 0) //?? ??? ???? ???? ????
	{
		temp.Add(figs[figs.GetSize() - 1]);//????? ?? ????? ?????? ????? 
		figs.RemoveAt(figs.GetSize() - 1);//???? ?? ????? ??????
		Invalidate(); // ???? ?? ???
	}
}
void CMFCprojectDlg::ToDo()
{
	if (temp.GetSize() != 0) // ?? ??? ?????? ?????? ?? ????
	{
		figs.InsertAt(figs.GetSize(), temp.GetAt(temp.GetSize() - 1));//????? ?????? ??????? 
		temp.RemoveAt(temp.GetSize() - 1);//????? ??????? ??????
		Invalidate();
	}
}


void CMFCprojectDlg::Pencil() // switch case 3 ?? ??????
{
	futureFigureKind = 3;
}
void CMFCprojectDlg::Retangle()
{
	futureFigureKind = 1;
}
void CMFCprojectDlg::Ellipse()
{
	futureFigureKind = 2;
}

void CMFCprojectDlg::newPage() // ???? ?? ????? 
{
	figs.RemoveAll(); 
	temp.RemoveAll();
	m_PenWidth = 1;
	Invalidate();
}
void CMFCprojectDlg::ChooseSave()
{
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}
void CMFCprojectDlg::ChooseLoad()
{
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}



void CMFCprojectDlg::OnFileSave32797()
{
	CMFCprojectDlg::ChooseSave();// ???? ????? ????
}

void CMFCprojectDlg::OnFileLoad()
{
	CMFCprojectDlg::ChooseLoad(); // ???? ?????? ????
}


void CMFCprojectDlg::OnPenwidthSmall()
{
	m_PenWidth = 1;// ???? ????? 

}


void CMFCprojectDlg::OnPenwidthLarge()
{
	m_PenWidth = 6;// ???? ????? 

}


void CMFCprojectDlg::OnPenwidthMedium()
{
	m_PenWidth = 3; // ???? ????? 
}


void CMFCprojectDlg::OnBnClickedMfccolorbutton1()
{
	outsideColor = outside_Color.GetColor(); // ???? ?? ???? ?????? 
}

void CMFCprojectDlg::OnBnClickedMfccolorbutton2()
{
	insideColor = inside_Color.GetColor(); // ???? ?? ???? ?????? 
}
void CMFCprojectDlg::IncreaseThin()
{
	if (m_PenWidth <= 30)
	{
		m_PenWidth += 2;
	}
	
}
void CMFCprojectDlg::DecreaseThin()
{
	if (m_PenWidth >= 2)
	{
		m_PenWidth -= 2;
	}
}
void CMFCprojectDlg::OnFileExit()
{
	CDialogEx::OnCancel();
}


void CMFCprojectDlg::OnBnClickedOk()
{
	CDialogEx::OnOK();
}



