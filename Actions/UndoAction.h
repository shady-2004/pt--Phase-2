#pragma once
#include "Action.h"
class UndoAction : public Action
{
	enum { MaxActionsToUndo = 5 };


public:
	static int UndoCount;
	UndoAction(ApplicationManager* pApp);

	void ReadActionParameters() {};

	virtual void Execute();
};
