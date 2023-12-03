#include "CSquare.h"
#include <fstream>

CSquare::CSquare(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqr to draw a square on the screen
	pOut->DrawSqr(Center, FigGfxInfo, Selected);
}

void CSquare::Save(ofstream& OutFile) {
	string dclr = "DRWCLR", fclr = "FCLR";
	OutFile << "SQUARE\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << dclr << "\t" << fclr << endl;
}

