#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo, int ID);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
	virtual void PrintInfo(Output*);	//Prints the figure's info

	virtual bool IsFound(int x, int y);
};

#endif