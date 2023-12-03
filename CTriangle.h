#pragma once
#include "Figures/CFigure.h"
class CTriangle :
    public CFigure
{
private:
    Point vertex1;
    Point vertex2;
    Point vertex3;
public:
    CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);

    virtual void Draw(Output* pOut) const;

    virtual void Save(ofstream& OutFile);
};

