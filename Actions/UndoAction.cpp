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
	UndoCount++;
	ActionsToUndoCount = 0;


	for (int i = 0; i < MaxActionsToUndo; i++)
		ActionsToUndo[i] = NULL;
}

void UndoAction::Execute()
{
	Action** ActionList = pManager->GetActionList();
	int ActionCount = pManager->GetActionCount();

	for (int i = 0; i < ActionCount; i++)
	{
		if (dynamic_cast<AddFigureAction*>(ActionList[i]) || dynamic_cast<DeleteFigureAction*>(ActionList[i]) || dynamic_cast<ChangeFigColorAction*>(ActionList[i]) || dynamic_cast<ChangeFillColorAcion*>(ActionList[i]) || dynamic_cast<MoveFigureAction*>(ActionList[i]))
		{
			ActionsToUndoCount++;

			if (ActionsToUndoCount > MaxActionsToUndo)
			{
				for (int i = 0; i < MaxActionsToUndo - 1; i++)			// Shifting The array of actions one to the left to make space for the new selected action
				{
					ActionsToUndo[i] = ActionsToUndo[i + 1];
				}

				ActionsToUndoCount = MaxActionsToUndo;
			}
			ActionsToUndo[ActionsToUndoCount - 1] = ActionList[i];
		}
	}
	if (ActionsToUndoCount == 0)
		return;
	if (UndoCount > ActionsToUndoCount)
		return;
	ActionsToUndo[ActionsToUndoCount - UndoCount]->UndoExecution();

}
void UndoAction::ReadActionParameters()
{
}
