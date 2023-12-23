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
 if(!Hidden)	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
 //PlaySound(TEXT("rectangle.wav"), NULL, SND_SYNC);
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

void CRectangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Figure Type : Rectangle          Figure ID : " + to_string(id) + "       Corner1 : " + to_string(Corner1.x) + "," + to_string(Corner1.y) + "   Corner2: " + to_string(Corner2.x) + "," + to_string(Corner1.y));

}

bool CRectangle::IsFound(int x, int y)
{
	if ((x <= Corner1.x != x <= Corner2.x )&& (y <= Corner1.y != y <= Corner2.y))
		return 1;
	return 0;
}

void CRectangle::MoveFigure(int a, int b)  // a function that modify the center of the selected figure to the new center 
{
	PreviousCorner1 = Corner1;
	PreviousCorner2 = Corner2;
	
	// a and b represent the center of the moved triangle //
// calculated the width of the triangle
	int width = abs(Corner1.y - Corner2.y);
	// calculated the length of the triangle
	int length = abs(Corner1.x - Corner2.x);
	//set the first corner to the new corner
	Corner1.x = a - length / 2.0;
	Corner1.y = b - width / 2.0;
	// set the second corner to the new corner
	Corner2.x = a + length / 2.0;
	Corner2.y = b + width / 2.0;

}

void CRectangle::ReturnFigure()
{
	Corner1 = PreviousCorner1;
	Corner2 = PreviousCorner2;
}

CRectangle::~CRectangle()
{
}
