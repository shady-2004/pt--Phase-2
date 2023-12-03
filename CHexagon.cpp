#include "CHexagon.h"
#include <fstream>

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P;
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a hexagon on the screen
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

void CHexagon::Save(ofstream& OutFile) {
	string dclr = "DRWCLR", fclr = "FCLR";
	OutFile << "HEX\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << dclr << "\t" << fclr << endl;
}
