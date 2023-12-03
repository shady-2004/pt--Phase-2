#include "CRectangle.h"
#include <fstream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Save(ofstream& OutFile) {
	string dclr = "DRWCLR", fclr = "FCLR";
	OutFile << "RECT\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << dclr << "\t" << fclr << endl;
}