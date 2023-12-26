#include "AddFigureAction.h"
#include "../ApplicationManager.h"

AddFigureAction::AddFigureAction(ApplicationManager* pApp) : Action(pApp)
{
	F = NULL;
}

void AddFigureAction::UndoExecution()
{
	if (F == NULL)
		return;
	pManager->DeleteFigure(F);
}

void AddFigureAction::RedoExecution()
{
	if (F == NULL)
		return;
	pManager->AddFigure(F);
}
