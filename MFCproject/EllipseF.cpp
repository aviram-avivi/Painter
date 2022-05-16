#include "stdafx.h"
#include "EllipseF.h"

IMPLEMENT_SERIAL(EllipseF, CObject, 1)
EllipseF::EllipseF()
{
}

EllipseF::EllipseF(CPoint p1, CPoint p2, int pen, COLORREF outsideColor, COLORREF insideColor):Figure(p1, p2,pen,outsideColor,insideColor)
{
	
}


void EllipseF::Draw(CDC* dc) const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPen myPen1(PS_SOLID, Pen_Thin, outsidecurColor);
	CPen* old_pen;
	CBrush myBrush(insidecurColor), * oldBrush;

	dc->SelectObject(&myPen1);
	dc->SelectObject(&myBrush);
	oldBrush = dc->SelectObject(&myBrush);
	old_pen= dc->SelectObject(&myPen1);
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
	dc->SelectObject(oldBrush);
	dc->SelectObject(old_pen);
	
}
