#include "CHexagon.h"

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P;
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a hexagon on the screen
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}
