#pragma once
#include "Figures/CFigure.h"
class CCircle :
    public CFigure
{
private:
    Point Center;
    Point Radius;//distance from center to surface
public:
    CCircle(Point, Point, GfxInfo FigureGfxInfo, int ID);
    virtual void Draw(Output* pOut) const;

};

