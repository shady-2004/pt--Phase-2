#include "CCircle.h"
#include <fstream>

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center =  P1;
	Radius = P2;
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCirc(Center, Radius, FigGfxInfo, Selected);
}

void CCircle::Save(ofstream& OutFile) {
	string dclr = "DRWCLR", fclr = "FCLR";
	OutFile << "CIRCLE\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << Radius.x << "\t" << Radius.y << "\t" << dclr << "\t" << fclr << endl;
}
