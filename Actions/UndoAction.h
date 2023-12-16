#pragma once
#include "Action.h"
class UndoAction : public Action
{
	enum {MaxActionsToUndo = 5};

private:
	
	Action* ActionsToUndo[MaxActionsToUndo];
	int ActionsToUndoCount;

public:
	static int UndoCount;
	UndoAction(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual void Execute();
};



