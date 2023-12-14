#include "CSquare.h"
#include <fstream>

CSquare::CSquare() {
	ShapeType = ITM_SQUARE;
}

CSquare::CSquare(Point P, GfxInfo FigureGfxInfo, int ID):CFigure(FigureGfxInfo)
{
	id = ID;
	Center = P;
	ShapeType = ITM_SQUARE;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqr to draw a square on the screen
	if (!IsHidden)
	pOut->DrawSqr(Center, FigGfxInfo, Selected);
}

void CSquare::Save(ofstream& OutFile) {
	OutFile << "SQUARE\t" << id << "\t" << Center.x << "\t" << Center.y << "\t" << FigGfxInfo.DrawClr << "\t";
	if (FigGfxInfo.isFilled) OutFile << FigGfxInfo.FillClr << endl;
	else OutFile << "NOFILL" << endl;
}

void CSquare::Load(ifstream& InFile) {
	InFile >> id >> Center.x >> Center.y >> &FigGfxInfo.DrawClr >> &FigGfxInfo.FillClr;
	if (FigGfxInfo.FillClr == LIGHTGOLDENRODYELLOW) FigGfxInfo.isFilled = false;
}

bool CSquare::IsFound(int x, int y)
{
	if (abs(x-Center.x) <=100 && abs(y-Center.y) <=100)
		return 1;
	return 0;
}

