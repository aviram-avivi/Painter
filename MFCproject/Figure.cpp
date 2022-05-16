#include "stdafx.h"  //!!! 1st include
#include "Figure.h"

//!! 22 b
IMPLEMENT_SERIAL(Figure, CObject, 1)
Figure::Figure()
{

}

Figure::Figure(CPoint p1, CPoint p2,int pen, COLORREF outsideColor, COLORREF insideColor):P1(p1), P2(p2)
{
	outsidecurColor = outsideColor;
	insidecurColor = insideColor;
	Pen_Thin = pen;
	
}

void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << P1;
		ar << P2;
		ar << Pen_Thin;
		ar << outsidecurColor;
		ar << insidecurColor;
	}
	else // Loading, not storing
	{
		ar >> P1;
		ar >> P2;
		ar >> Pen_Thin;
		ar >> outsidecurColor;
		ar >> insidecurColor;
	}
}

bool Figure::isInside(const CPoint &P) const
{
	return (P1.x <= P.x && P.x <= P2.x || P1.x >= P.x && P.x >= P2.x) &&
		(P1.y <= P.y && P.y <= P2.y || P1.y >= P.y && P.y >= P2.y);
}
void Figure::Shift(int dx, int dy)
{
	P1 = P1 + CPoint(dx, dy);
	P2 = P2 + CPoint(dx, dy);
}

void Figure::Draw(CDC* dc) const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPen myPen1(PS_SOLID, Pen_Thin, outsidecurColor);
	CPen* old_pen;
	CBrush myBrush(insidecurColor), * oldBrush;
	
	
	dc->SelectObject(&myPen1);
	dc->SelectObject(&myBrush);
	oldBrush = dc->SelectObject(&myBrush);
	old_pen = dc->SelectObject(&myPen1);
	dc->Rectangle(P1.x, P1.y, P2.x, P2.y);
	dc->SelectObject(oldBrush);
	dc->SelectObject(old_pen);

}

CPoint Figure::getP1() const
{
	return P1;
}

CPoint Figure::getP2() const
{
	return P2;
}

