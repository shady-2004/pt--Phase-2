#include "RedoAction.h"
#include "../ApplicationManager.h"
#include "AddFigureAction.h"
#include "DeleteFigureAction.h"
#include "ChangeFigColorAction.h"
#include "ChangeFillColorAcion.h"
#include "MoveFigureAction.h"
#include "AddCircAction.h"

int RedoAction::RedoCount = 0;
RedoAction::RedoAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RedoAction::ReadActionParameters()
{

}

void RedoAction::Execute()
{
	RedoCount++;
	if (RedoCount > UndoAction::UndoCount)
	{
		pManager->GetOutput()->PrintMessage("No more Actions to redo!");
		RedoCount--;
		return;
	}


	Action** ActionList = pManager->GetActionList();
	int ActionCount = pManager->GetActionCount();

	ActionList[ActionCount]->RedoExecution();
	ActionCount++;
	pManager->SetActionCount(ActionCount);

}
