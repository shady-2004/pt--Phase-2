#pragma once
#include "Figures/CFigure.h"
class CSquare :
    public CFigure
{
private:
	Point Center;

public:
	CSquare(Point, GfxInfo FigureGfxInfo, int ID);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
};

