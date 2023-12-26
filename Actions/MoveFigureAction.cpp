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

bool MoveFigureAction::Execute()
{
	SelectedFig = pManager->GetSelectedFig();
	if (SelectedFig == NULL)
		return 0;

	ReadActionParameters();
	
	SelectedFig->MoveFigure(x, y);
	pManager->GetOutput()->PrintMessage("Figure Moved");

	SelectedFig->SetSelected(0);
	pManager->SetSelectedFig(NULL);

	return 1;
}

void MoveFigureAction::UndoExecution()
{
	SelectedFig->ReturnFigure();

	pManager->GetOutput()->PrintMessage("Move Figure Action Undone");
}

void MoveFigureAction::RedoExecution()
{
	SelectedFig->MoveFigure(x, y);

	pManager->GetOutput()->PrintMessage("Move Figure Action Redone");
}
