#pragma once
#include "CFigure.h"
class CSquare :
    public CFigure
{
private:
	Point Center;

public:
	CSquare(Point, GfxInfo FigureGfxInfo, int ID);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);

	virtual bool IsFound(int, int);
};

