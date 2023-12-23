#include "AddTriAction.h"
#include"../Figures/CTriangle.h"
#include"../GUI/Input.h"
#include"../GUI/Output.h"
#include"../ApplicationManager.h"
AddTriAction::AddTriAction(ApplicationManager* pApp):AddFigureAction(pApp)
{
}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first Vertex");

	//Read 1st Vertex and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second Vertex");

	//Read 2nd Vertex and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third Vertex");

	//Read 3rd Vertex and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	TriGfxInfo.isFilled = pOut->getCrntFillStatus();


	pOut->ClearStatusBar();

}
void AddTriAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	F = new CTriangle(P1, P2,P3, TriGfxInfo, (pManager->GetFigCount()) + 1);

	//Add the Triangle to the list of figures
	pManager->AddFigure(F);
	PlaySound(TEXT("triangle.wav"), NULL, SND_SYNC);
}

void AddTriAction::UndoExecution()
{
	pManager->DeleteFigure(F);
	pManager->GetOutput()->PrintMessage("Draw Triangle Action Undone");
}
