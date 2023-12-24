#include "AddCircAction.h"
#include"../GUI/Input.h"
#include"../GUI/Output.h"
#include"../ApplicationManager.h"
#include<Windows.h>
#include<MMSystem.h>
AddCircAction::AddCircAction(ApplicationManager* pApp) :AddFigureAction(pApp)
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
	pIn->GetPointClicked(PointOnRadius.x, PointOnRadius.y);

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

	//Create a circle with the parameters read from the user
	 F = new CCircle(Center, PointOnRadius, CircGfxInfo, (pManager->GetFigCount()) + 1);

	//Add the cirlce to the list of figures
	pManager->AddFigure(F);
	//display figure`s sound if the sound is enabled
	if (pManager->getEnableSound())          // check if the sound is enabled 
	PlaySound(TEXT("circle.wav"), NULL, SND_ASYNC);
}

void AddCircAction::UndoExecution()
{
	pManager->DeleteFigure(F);
	pManager->GetOutput()->PrintMessage("Draw Circle Action Undone");
}

