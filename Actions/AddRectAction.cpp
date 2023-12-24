#include "AddRectAction.h"
#include"../Figures/CRectangle.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):AddFigureAction(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.isFilled = pOut->getCrntFillStatus();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	F=new CRectangle(P1, P2, RectGfxInfo, (pManager->GetFigCount())+1);

	//Add the rectangle to the list of figures
	pManager->AddFigure(F);
}

void AddRectAction::UndoExecution()
{
	AddFigureAction::UndoExecution();
	pManager->GetOutput()->PrintMessage("Draw Rectangle Action Undone");
}

void AddRectAction::RedoExecution()
{
	AddFigureAction::RedoExecution();
	pManager->GetOutput()->PrintMessage("Draw Rectangle Action Redone");
}
