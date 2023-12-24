#include "MoveFigureAction.h"
#include "..\ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
MoveFigureAction::MoveFigureAction(ApplicationManager* pApp) :Action(pApp)
{
}

void MoveFigureAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage(" Move Figure: Please click at a point ");
	pIn->GetPointClicked(x, y);

}

void MoveFigureAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	SelectedFig = pManager->GetSelectedFig();
	if (SelectedFig == NULL) {
		pOut->PrintMessage(" Error! Please select a figure first ");
		return;
	}
	ReadActionParameters();
	
	SelectedFig->MoveFigure(x, y);
}

void MoveFigureAction::UndoExecution()
{
	if (SelectedFig == NULL)
		return;
	SelectedFig->ReturnFigure();

	pManager->GetOutput()->PrintMessage("Move Figure Action Undone");
}
