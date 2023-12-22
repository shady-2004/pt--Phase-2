#include "CTriangle.h"
#include <fstream>

CTriangle::CTriangle() {
	ShapeType = "Triangle";
}

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo, int ID) :CFigure(FigureGfxInfo)
{
	id = ID;
	vertex1 = P1;
	vertex2 = P2;
	vertex3 = P3;
	ShapeType = "Triangle";
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	if (!Hidden)
	pOut->DrawTri(vertex1, vertex2, vertex3, FigGfxInfo, Selected);
}


void CTriangle::Save(ofstream& OutFile) {
	OutFile << "TRIANG\t" << id << "\t" << vertex1.x << "\t" << vertex1.y << "\t" << vertex2.x << "\t" << vertex2.y << "\t" << vertex3.x << "\t" << vertex3.y << "\t" << FigGfxInfo.DrawClr << "\t";
	if (FigGfxInfo.isFilled) OutFile << FigGfxInfo.FillClr << endl;
	else OutFile << "NOFILL" << endl;
}

void CTriangle::Load(ifstream& InFile) {
	InFile >> id >> vertex1.x >> vertex1.y >> vertex2.x >> vertex2.y >> vertex3.x >> vertex3.y >> &FigGfxInfo.DrawClr >> &FigGfxInfo.FillClr;
	if (FigGfxInfo.FillClr == LIGHTGOLDENRODYELLOW) FigGfxInfo.isFilled = false;
}

bool CTriangle::IsFound(int x, int y)
{
	int intersections = 0;
	int n = 3;
	Point trianglePoints[] = { vertex1, vertex2, vertex3};
	double x1, y1, x2, y2;

	double intersectionPoint;
	for (int i = 0 , j = n-1; i < n; j = i++)
	{
		x1 = trianglePoints[i].x;
		y1= trianglePoints[i].y;

		x2= trianglePoints[j].x;
		y2= trianglePoints[j].y;

		intersectionPoint = x1 + (y - y1) / (y2 - y1) * (x2 - x1);
		if ((y < y1 != y < y2) && x < intersectionPoint)
			intersections++;
	}
	if (intersections % 2 == 1)
		return true;
	return false;
}

void CTriangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Figure Type : Triangle         Figure ID : " + to_string(id) + "         Vertex1 : " + to_string(vertex1.x) + "," + to_string(vertex1.y) + "   Vertex2: " + to_string(vertex2.x) + "," + to_string(vertex2.y) + "   Vertex3: " + to_string(vertex3.x) + "," + to_string(vertex3.y));

}

