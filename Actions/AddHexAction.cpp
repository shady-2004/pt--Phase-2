#include "AddHexAction.h"
#include"../Figures/CHexagon.h"
#include"../GUI/Input.h"
#include"../GUI/Output.h"
#include"../ApplicationManager.h"

AddHexAction::AddHexAction(ApplicationManager* pApp):AddFigureAction(pApp)
{
}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Center");

	//Read Center and store in point Center
	pIn->GetPointClicked(Center.x, Center.y);


	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();
	HexGfxInfo.isFilled = pOut->getCrntFillStatus();

	pOut->ClearStatusBar();
}

//Execute the action
void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	if (Center.y - 86 < UI.ToolBarHeight || Center.y + 86 > UI.height - UI.StatusBarHeight) //Draw Validation
	{
		pManager->GetOutput()->PrintMessage("Error :Can't draw here ");
		return;
	}

	//Create a hexagon with the parameters read from the user
	F = new CHexagon(Center, HexGfxInfo, (pManager->GetFigCount()) + 1);

	//Add the hexagon to the list of figures
	pManager->AddFigure(F);
}

void AddHexAction::UndoExecution()
{
	AddFigureAction::UndoExecution();
	pManager->GetOutput()->PrintMessage("Draw Hexagon Action Undone");
}

void AddHexAction::RedoExecution()
{
	AddFigureAction::RedoExecution();
	pManager->GetOutput()->PrintMessage("Draw Hexagon Action Redone");
}

