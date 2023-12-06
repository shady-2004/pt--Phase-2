#pragma once
#include "CFigure.h"
class CSquare :
    public CFigure
{
private:
	Point Center;

public:
	CSquare();
	CSquare(Point, GfxInfo FigureGfxInfo, int ID);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
	virtual bool IsFound(int, int);
};

