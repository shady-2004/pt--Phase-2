#include "DeleteFigureAction.h"
#include "../ApplicationManager.h"
#include "../Figures/CFigure.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteFigureAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
}

void DeleteFigureAction::Execute()
{
	temp = pManager->GetSelectedFig();
	if (temp == NULL)
		return;

	ReadActionParameters();
	
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
