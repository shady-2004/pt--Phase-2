#include "CHexagon.h"
#include <fstream>

CHexagon::CHexagon() {

}

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo, int ID):CFigure(FigureGfxInfo)
{
	id = ID;
	Center = P;
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a hexagon on the screen
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

void CHexagon::Save(ofstream& OutFile) {
	OutFile << "HEX\t" << id << "\t" << Center.x << "\t" << Center.y << "\t" << FigGfxInfo.DrawClr << "\t";
	if (FigGfxInfo.isFilled) OutFile << FigGfxInfo.FillClr << endl;
	else OutFile << "NOFILL" << endl;
}

void CHexagon::Load(ifstream& InFile) {
	InFile >> id >> Center.x >> Center.y >> &FigGfxInfo.DrawClr >> &FigGfxInfo.FillClr;
	if (FigGfxInfo.FillClr == LIGHTGOLDENRODYELLOW) FigGfxInfo.isFilled = false;
}

bool CHexagon::IsFound(int x, int y)
{
	return false;
}
