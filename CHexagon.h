#pragma once
#include "Figures/CFigure.h"
class CHexagon :
    public CFigure
{
private:
    Point Center;
public:
    CHexagon(Point, GfxInfo FigureGfxInfo, int ID);
    virtual void Draw(Output* pOut) const;
};

