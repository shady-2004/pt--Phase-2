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

void DeleteFigureAction::Execute()
{
	temp = pManager->GetSelectedFig();
	if (temp == NULL)
		return;

	ReadActionParameters();
	
	pManager->GetSelectedFig()->SetSelected(0);
	pManager->SetSelectedFig(NULL);
	pManager->DeleteFigure(temp);
}

void DeleteFigureAction::UndoExecution()
{
	if (temp == NULL)
		return;
	pManager->AddFigure(temp);
	pManager->GetOutput()->PrintMessage("Delete Figure Action Undone");
}

void DeleteFigureAction::RedoExecution()
{
	if (temp == NULL)
		return;
	pManager->DeleteFigure(temp);
	pManager->GetOutput()->PrintMessage("Delete Figure Action Undone");
}