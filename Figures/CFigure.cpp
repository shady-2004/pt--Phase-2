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
	FigGfxInfo.isFilled = UI.IsFilled;
	if (UI.IsFilled == true)
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
	if (FigGfxInfo.FillClr == BLUE) return "BLUE";
	else if (FigGfxInfo.FillClr == GREEN) return "GREEN";
	else if (FigGfxInfo.FillClr == RED) return "RED";
	else if (FigGfxInfo.FillClr == YELLOW) return "YELLOW";
	else if (FigGfxInfo.FillClr == ORANGE) return "ORANGE";
	else if (FigGfxInfo.FillClr == BLACK) return "BLACK";
	else return "NO FILL";
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

DrawMenuItem CFigure::getShapeType()
{
	return ShapeType;
}

int CFigure::getShapeFillColor()
{
	if (!FigGfxInfo.isFilled)
		return 10;//Refers to Unfilled
	if (FigGfxInfo.FillClr == RED)
		return COLOR_RED;
	if (FigGfxInfo.FillClr == BLUE)
		return COLOR_BLUE;
	if (FigGfxInfo.FillClr == GREEN)
		return COLOR_GREEN;
	if (FigGfxInfo.FillClr == ORANGE)
		return COLOR_ORANGE;
	if (FigGfxInfo.FillClr == YELLOW)
		return COLOR_YELLOW;
	if (FigGfxInfo.FillClr == BLACK)
		return COLOR_BLACK;

}

CFigure::~CFigure()
{
}
