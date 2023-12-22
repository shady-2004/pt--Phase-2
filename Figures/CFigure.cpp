#include "CFigure.h"

CFigure::CFigure() {
	Selected = false;
	Hidden = 0;
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	Hidden = 0;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

string CFigure::convertDrwColorToString() const {
	if (FigGfxInfo.DrawClr == BLUE) return "BLUE";
	else if (FigGfxInfo.DrawClr == GREEN) return "GREEN";
	else if (FigGfxInfo.DrawClr == RED) return "RED";
	else if (FigGfxInfo.DrawClr == YELLOW) return "YELLOW";
	else if (FigGfxInfo.DrawClr == ORANGE) return "ORANGE";
	else if (FigGfxInfo.DrawClr == BLACK) return "BLACK";
}

string CFigure::convertFillColorToString() const {

	if(!FigGfxInfo.isFilled) return"NO FILL";
	if (FigGfxInfo.FillClr == BLUE) return "BLUE";
	else if (FigGfxInfo.FillClr == GREEN) return "GREEN";
	else if (FigGfxInfo.FillClr == RED) return "RED";
	else if (FigGfxInfo.FillClr == YELLOW) return "YELLOW";
	else if (FigGfxInfo.FillClr == ORANGE) return "ORANGE";
    if (FigGfxInfo.FillClr == BLACK) return "BLACK";
}

color CFigure::convertColorToClr(string clr) const {
	if (clr == "BLUE") return BLUE;
	else if (clr == "GREEN") return GREEN;
	else if (clr == "RED") return RED;
	else if (clr == "YELLOW") return YELLOW;
	else if (clr == "ORANGE") return ORANGE;
	else if (clr == "BLACK") return BLACK;
	else return WHITE;
}


void CFigure::SetHidden(bool x)
{
	Hidden = x;
}

bool CFigure::IsHidden()
{
	return Hidden;
}

string CFigure::getShapeType()
{
	return ShapeType;
}
