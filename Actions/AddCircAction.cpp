#include "AddCircAction.h"
#include"../Figures/CCircle.h"
#include"../GUI/Input.h"
#include"../GUI/Output.h"
#include"../ApplicationManager.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center");

	//Read Center and store in point Center
	pIn->GetPointClicked(Center.x, Center.y);

	pOut->PrintMessage("New Circle: Click at Radius");

	//Read Radius and store in Radius
	pIn->GetPointClicked(Radius.x, Radius.y);

	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.isFilled= pOut->getCrntFillStatus();

	pOut->ClearStatusBar();
}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	id = pManager->GetActionCount();

	//Create a circle with the parameters read from the user
	CCircle* C = new CCircle(Center, Radius, CircGfxInfo, (pManager->GetFigCount()) + 1);

	//Add the cirlce to the list of figures
	pManager->AddFigure(C);
}