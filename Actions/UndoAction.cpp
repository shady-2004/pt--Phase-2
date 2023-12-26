#include "UndoAction.h"
#include"../ApplicationManager.h"
#include "AddFigureAction.h"
#include "DeleteFigureAction.h"
#include "ChangeFigColorAction.h"
#include "ChangeFillColorAcion.h"
#include "MoveFigureAction.h"

int UndoAction::UndoCount = 0;
UndoAction::UndoAction(ApplicationManager* pApp) : Action(pApp)
{
}

bool UndoAction::Execute()
{

	Action** ActionList = pManager->GetActionList();
	int &ActionCount = pManager->GetActionCount();

	if (ActionCount > MaxActionsToUndo)
	{
		for (int i = 0; i < ActionCount - MaxActionsToUndo; i++)
			delete ActionList[i];

		for (int i = 0; i < MaxActionsToUndo; i++)
		{
			ActionList[i] = ActionList[ActionCount - MaxActionsToUndo + i];
		}
		ActionCount = MaxActionsToUndo;
	}

	if (ActionCount == 0)
	{
		pManager->GetOutput()->PrintMessage("No more Actions to Undo!");
		return 0;
	}
	ActionList[ActionCount - 1]->UndoExecution();
	ActionCount--;
	UndoCount++;
}
