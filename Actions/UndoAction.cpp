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
void UndoAction::ReadActionParameters()
{
}

void UndoAction::Execute()
{

	Action** ActionList = pManager->GetActionList();
	int ActionCount = pManager->GetActionCount();

	if (ActionCount > MaxActionsToUndo)
	{
		for (int i = 0; i < MaxActionsToUndo; i++)
		{
			ActionList[i] = ActionList[ActionCount - MaxActionsToUndo + i];
		}
		ActionCount = MaxActionsToUndo;
		pManager->SetActionCount(ActionCount);
	}

	if (ActionCount == 0)
	{
		pManager->GetOutput()->PrintMessage("No more Actions to Undo!");
		return;
	}
	ActionList[ActionCount - 1]->UndoExecution();
	//ActionsToUndo[ActionsToUndoCount - 1] = NULL;
	ActionCount--;
	pManager->SetActionCount(ActionCount);
	UndoCount++;
}
