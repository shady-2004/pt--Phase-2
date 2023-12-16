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
	if (!Hidden)
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

void CSquare::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Figure Type : Square          Figure ID : " + to_string(id) + "         Center : " + to_string(Center.x) + "," + to_string(Center.y));
}


void CSquare::MoveFigure(int a, int b)  // a function that modify the center of the selected figure to the new center 
{
	PreviousCenter = Center;
	Center.x = a;
	Center.y = b;

}

void CSquare::ReturnFigure()
{
	Center = PreviousCenter;
}

CSquare::~CSquare()
{
}

