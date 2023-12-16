#pragma once
#include "CFigure.h"
class CCircle :
    public CFigure
{
private:
    Point Center;
    Point Radius;//distance from center to surface
public:
    CCircle();
    CCircle(Point, Point, GfxInfo FigureGfxInfo, int ID);

    virtual void Draw(Output* pOut) const;

    virtual void Save(ofstream& OutFile);
    virtual void Load(ifstream& InFile);

    virtual bool IsFound(int x, int y);
    virtual void PrintInfo(Output* pOut);

    int CalcRadius();

    virtual ~CCircle();
};

