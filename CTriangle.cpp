#include "CTriangle.h"
#include <fstream>

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	vertex1 = P1;
	vertex2 = P2;
	vertex3 = P3;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(vertex1, vertex2, vertex3, FigGfxInfo, Selected);
}


void CTriangle::Save(ofstream& OutFile) {
	string dclr = "DRWCLR", fclr = "FCLR";
	OutFile << "TRIANGLE\t" << ID << "\t" << vertex1.x << "\t" << vertex1.y << "\t" << vertex2.x << "\t" << vertex2.y << "\t"  << vertex3.x << "\t" << vertex3.y << "\t" << dclr << "\t" << fclr << endl;
}

