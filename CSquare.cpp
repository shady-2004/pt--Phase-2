#include "CSquare.h"

CSquare::CSquare(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqr to draw a square on the screen
	pOut->DrawSqr(Center, FigGfxInfo, Selected);
}
