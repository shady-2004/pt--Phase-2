#include "CRectangle.h"
#include <fstream>

CRectangle::CRectangle() {
	ShapeType = ITM_RECT;
}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo, int ID):CFigure(FigureGfxInfo)
{
	id = ID;
	Corner1 = P1;
	Corner2 = P2;
	ShapeType = ITM_RECT;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen
 if(!IsHidden)	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Save(ofstream& OutFile) {
	OutFile << "RECT\t" << id << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << FigGfxInfo.DrawClr << "\t";
	if (FigGfxInfo.isFilled) OutFile << FigGfxInfo.FillClr << endl;
	else OutFile << "NOFILL" << endl;
}

void CRectangle::Load(ifstream& InFile) {
	InFile >> id >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> &FigGfxInfo.DrawClr >> &FigGfxInfo.FillClr;
	if (FigGfxInfo.FillClr == LIGHTGOLDENRODYELLOW) FigGfxInfo.isFilled = false;
}

void CRectangle::Print(Output* pOut)
{
	CFigure::Print(pOut);
	pOut->PrintMessage("Corner1 : " + to_string(Corner1.x) + "," + to_string(Corner1.y) + "   Corner2: " + to_string(Corner2.x) + "," + to_string(Corner1.y));

}

bool CRectangle::IsFound(int x, int y)
{
	if (x >= Corner1.x && x <= Corner2.x && y >= Corner1.y && y <= Corner2.y)
		return 1;
	return 0;
}
