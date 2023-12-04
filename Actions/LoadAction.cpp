#include "LoadAction.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CCircle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CSquare.h"
#include <fstream>
#include <iostream>

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp){

}

void LoadAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the name of the file you want to load from: " + filename);
	filename = pIn->GetString(pOut);
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
}

void LoadAction::Execute() {
	ReadActionParameters();
	id = pManager->GetActionCount();
	string dclr, fclr;
	int num;
	ifstream InFile;
	InFile.open("Saved Data/" + filename + ".txt");
	if (InFile.fail()) { pManager->GetOutput()->PrintMessage("No such file to load. Enter a valid file!"); return; }
	InFile >> dclr >> fclr >> num;
	while (num--) {
		string shape,shape2;
		CFigure* fig;
		InFile >> shape;
		if (shape == "RECT") fig = new CRectangle;
		else if (shape == "SQUARE") fig = new CSquare;
		else if (shape == "TRIANG") fig = new CTriangle;
		else if (shape == "HEX") fig = new CHexagon;
		else if (shape == "CIRCLE") fig = new CCircle;
		fig->Load(InFile);
		pManager->AddFigure(fig);
	}
}