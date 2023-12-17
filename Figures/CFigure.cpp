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
	else
		return 10;//Refers to Unfilled

}

CFigure::~CFigure()
{
}
