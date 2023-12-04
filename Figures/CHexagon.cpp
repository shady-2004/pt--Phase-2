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
	string dclr = convertDrwColorToString(), fclr = convertFillColorToString();
	OutFile << "HEX\t" << id << "\t" << Center.x << "\t" << Center.y << "\t" << dclr << "\t" << fclr << endl;
}

void CHexagon::Load(ifstream& InFile) {
	string dclr, fclr;
	InFile >> id >> Center.x >> Center.y >> dclr >> fclr;
	FigGfxInfo.DrawClr = convertColorToClr(dclr);
	FigGfxInfo.FillClr = convertColorToClr(fclr);
}

bool CHexagon::IsFound(int x, int y)
{
	return false;
}
