#include "CTriangle.h"
#include <fstream>

CTriangle::CTriangle() {

}

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo, int ID) :CFigure(FigureGfxInfo)
{
	id = ID;
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
	OutFile << "TRIANG\t" << id << "\t" << vertex1.x << "\t" << vertex1.y << "\t" << vertex2.x << "\t" << vertex2.y << "\t"  << vertex3.x << "\t" << vertex3.y << "\t" << dclr << "\t" << fclr << endl;
}

void CTriangle::Load(ifstream& InFile) {
	string test, test2;
	InFile >> id >> vertex1.x >> vertex1.y >> vertex2.x >> vertex2.y >> vertex3.x >> vertex3.y;
}

bool CTriangle::IsFound(int, int)
{
	return false;
}

