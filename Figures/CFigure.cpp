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


string CFigure::convertFillColorToString() const {

	if(!FigGfxInfo.isFilled) return"NO FILL";
	if (FigGfxInfo.FillClr == BLUE) return "BLUE";
	else if (FigGfxInfo.FillClr == GREEN) return "GREEN";
	else if (FigGfxInfo.FillClr == RED) return "RED";
	else if (FigGfxInfo.FillClr == YELLOW) return "YELLOW";
	else if (FigGfxInfo.FillClr == ORANGE) return "ORANGE";
    if (FigGfxInfo.FillClr == BLACK) return "BLACK";
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

CFigure::~CFigure()
{
}
