#include "CCircle.h"
#include <fstream>
#include <iostream>

using namespace std;

CCircle::CCircle() {

}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo, int ID):CFigure(FigureGfxInfo)
{
	id = ID;
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
	OutFile << "CIRCLE\t" << id << "\t" << Center.x << "\t" << Center.y << "\t" << Radius.x << "\t" << Radius.y << "\t" << dclr << "\t" << fclr << endl;
}

void CCircle::Load(ifstream& InFile) {
	InFile >> id >> Center.x >> Center.y >> Radius.x >> Radius.y;
}

bool CCircle::IsFound(int x, int y)
{
	int Radius = sqrt(pow(this->Radius.x - Center.x, 2) + pow(this->Radius.y - Center.y, 2));

	int distanceFromCenter = sqrt(pow(x - Center.x, 2) + pow(y - Center.y, 2));

	if (distanceFromCenter <= Radius)
		return 1;
	return 0;
}