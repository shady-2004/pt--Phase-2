#pragma once
#include "Action.h"
#include "UndoAction.h"
class RedoAction : public Action
{
public:
	static int RedoCount;
	RedoAction(ApplicationManager* pApp);

	void ReadActionParameters() {};

	virtual void Execute();
};

