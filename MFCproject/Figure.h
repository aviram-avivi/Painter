#pragma once
#include "stdafx.h"
class Figure: public CObject {
	DECLARE_SERIAL(Figure) 
	CPoint P1;
	CPoint P2;

public:
	Figure();
	Figure(CPoint p1, CPoint p2, int pen, COLORREF outsideColor, COLORREF insideColor);
	void Serialize(CArchive& ar);
	virtual void Draw(CDC* dc) const;
	CPoint getP1() const;
	CPoint getP2() const;
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
	virtual bool isInside(const CPoint &P) const;
	virtual void Shift(int dx, int dy);
protected:
	COLORREF outsidecurColor;
	COLORREF insidecurColor;
	int Pen_Thin;
	bool emptyOrNot;
};

