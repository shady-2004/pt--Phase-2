#include "DeleteFigureAction.h"
#include "../ApplicationManager.h"
#include "../Figures/CFigure.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteFigureAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Selected Figure is deleted");
}

bool DeleteFigureAction::Execute()
{
	temp = pManager->GetSelectedFig();
	if (temp == NULL)
		return 0;

	ReadActionParameters();
	
	pManager->GetSelectedFig()->SetSelected(0);
	pManager->SetSelectedFig(NULL);
	pManager->DeleteFigure(temp);

	return 1;
}

void DeleteFigureAction::UndoExecution()
{
	pManager->AddFigure(temp);
	pManager->GetOutput()->PrintMessage("Delete Figure Action Undone");
}

void DeleteFigureAction::RedoExecution()
{
	pManager->DeleteFigure(temp);
	pManager->GetOutput()->PrintMessage("Delete Figure Action Redone");
}