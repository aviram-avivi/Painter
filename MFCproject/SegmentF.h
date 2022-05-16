#pragma once
#include "Figure.h"
class SegmentF :public Figure
{
	DECLARE_SERIAL(SegmentF)
public:
	SegmentF();
	SegmentF(CPoint p1, CPoint p2,int pen, COLORREF color);
	void Draw(CDC* dc) const;
};

