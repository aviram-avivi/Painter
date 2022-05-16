#include "stdafx.h" 
#include "RectangleF.h"

IMPLEMENT_SERIAL(RectangleF, CObject, 1)

RectangleF::RectangleF()
{
}
RectangleF::RectangleF(CPoint p1, CPoint p2, int pen, COLORREF outsideColor, COLORREF insideColor) :Figure(p1,p2,pen,outsideColor,insideColor)
{

}
