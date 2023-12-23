#include "AddSqrAction.h"
#include"../Figures/CSquare.h"
#include"../GUI/Input.h"
#include"../GUI/Output.h"
#include"../ApplicationManager.h"
AddSqrAction::AddSqrAction(ApplicationManager* pApp):AddFigureAction(pApp)
{
}

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at Square center");

	//Read center of square
	pIn->GetPointClicked(P1.x, P1.y);


	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();
	SqrGfxInfo.isFilled = pOut->getCrntFillStatus();

	pOut->ClearStatusBar();
}
//Execute the action
void AddSqrAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Square with the parameters read from the user
	F = new CSquare(P1,  SqrGfxInfo, (pManager->GetFigCount()) + 1);

	//Add the Square to the list of figures
	pManager->AddFigure(F);
	PlaySound(TEXT("square.wav"), NULL, SND_SYNC);
}

void AddSqrAction::UndoExecution()
{
	pManager->DeleteFigure(F);
	pManager->GetOutput()->PrintMessage("Draw Square Action Undone");
}
