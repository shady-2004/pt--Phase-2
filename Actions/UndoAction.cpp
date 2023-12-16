#include "UndoAction.h"
#include"../ApplicationManager.h"
#include "AddRectAction.h"
UndoAction::UndoAction(ApplicationManager* pApp) : Action(pApp)
{
}

void UndoAction::Execute()
{
	lastAction = pManager->GetActionList()[pManager->GetActionCount()-1];

	AddRectAction* castedRect = dynamic_cast<AddRectAction*>(lastAction);

	//if (castedRect)
		//castedRect->

}

void UndoAction::ReadActionParameters()
{
}
