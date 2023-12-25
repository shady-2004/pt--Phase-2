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
	pIn->GetPointClicked(Center.x, Center.y);


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

	if (Center.y - 75 < UI.ToolBarHeight || Center.y + 75 > UI.height - UI.StatusBarHeight) //Draw Validation
	{
		pManager->GetOutput()->PrintMessage("Error :Can't draw here ");
			return;
	}

	//Create a Square with the parameters read from the user
	F = new CSquare(Center,  SqrGfxInfo, (pManager->GetFigCount()) + 1);

	//Add the Square to the list of figures
	pManager->AddFigure(F);
}

void AddSqrAction::UndoExecution()
{
	AddFigureAction::UndoExecution();
	pManager->GetOutput()->PrintMessage("Draw Square Action Undone");
}

void AddSqrAction::RedoExecution()
{
	AddFigureAction::RedoExecution();
	pManager->GetOutput()->PrintMessage("Draw Square Action Redone");
}
