#pragma once
#include "CFigure.h"
class CTriangle :
    public CFigure
{
private:
    Point vertex1;
    Point vertex2;
    Point vertex3;

public:
    CTriangle();
    CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo,int ID);

    virtual void Draw(Output* pOut) const;

    virtual void Save(ofstream& OutFile);
    virtual void Load(ifstream& InFile);
    virtual bool IsFound(int x, int y);

    virtual void PrintInfo(Output* pOut);
};

