#pragma once
#include "Figure.h"
class RectangleF : public Figure 
{
	DECLARE_SERIAL(RectangleF)  
public:
	RectangleF();
	RectangleF(CPoint p1, CPoint p2, int pen, COLORREF outsideColor, COLORREF insideColor);

protected:
	COLORREF curColor;
	int Pen_Thin;
};

