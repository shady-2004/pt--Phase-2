#include "CCircle.h"
#include <fstream>
#include <iostream>

using namespace std;

CCircle::CCircle() {
	ShapeType=ITM_CIRCLE;
}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo, int ID):CFigure(FigureGfxInfo)
{
	id = ID;
	Center =  P1;
	Radius = P2;
	ShapeType = ITM_CIRCLE;
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	if(!Hidden)
	pOut->DrawCirc(Center, Radius, FigGfxInfo, Selected);
}

void CCircle::Save(ofstream& OutFile) {
	OutFile << "CIRCLE\t" << id << "\t" << Center.x << "\t" << Center.y << "\t" << Radius.x << "\t" << Radius.y << "\t" << FigGfxInfo.DrawClr << "\t";
	if (FigGfxInfo.isFilled) OutFile << FigGfxInfo.FillClr << endl;
	else OutFile << "NOFILL" << endl;
}

void CCircle::Load(ifstream& InFile) {
	InFile >> id >> Center.x >> Center.y >> Radius.x >> Radius.y >> &FigGfxInfo.DrawClr >> &FigGfxInfo.FillClr;
	if (FigGfxInfo.FillClr == LIGHTGOLDENRODYELLOW) FigGfxInfo.isFilled = false;
}

bool CCircle::IsFound(int x, int y)
{
	int Radius = CalcRadius();

	int distanceFromCenter = sqrt(pow(x - Center.x, 2) + pow(y - Center.y, 2));

	if (distanceFromCenter <= Radius)
		return 1;
	return 0;
}

void CCircle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Figure Type : Circle        Figure ID : " + to_string(id) + "      Center : " + to_string(Center.x) + "," + to_string(Center.y) + "   Radius =  " + to_string(CalcRadius()));

}

int CCircle::CalcRadius()
{
	int Radius = sqrt(pow(this->Radius.x - Center.x, 2) + pow(this->Radius.y - Center.y, 2));
	return Radius;
}
