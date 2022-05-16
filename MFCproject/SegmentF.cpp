#include "stdafx.h"
#include "SegmentF.h"


IMPLEMENT_SERIAL(SegmentF, CObject, 1)

SegmentF::SegmentF()
{
}

SegmentF::SegmentF(CPoint p1, CPoint p2,int pen, COLORREF color) :Figure(p1, p2, pen, color, color)
{
}
void SegmentF::Draw(CDC* dc) const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPen myPen1(PS_SOLID, Pen_Thin, outsidecurColor);
	CPen* old_pen;
	old_pen = dc->SelectObject(&myPen1);
	dc->MoveTo(p1.x, p1.y);
	dc->LineTo(p2.x, p2.y);
	dc->SelectObject(old_pen);

}