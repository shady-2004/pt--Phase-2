#include "AddFigureAction.h"
#include "../ApplicationManager.h"

AddFigureAction::AddFigureAction(ApplicationManager* pApp) : Action(pApp)
{
}

void AddFigureAction::UndoExecution()
{
	pManager->DeleteFigure(F);
}

void AddFigureAction::RedoExecution()
{
	pManager->AddFigure(F);
}
