#pragma once
#include "Action.h"
class UndoAction : public Action
{
private:
	Action* lastAction;
public:
	UndoAction(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual void Execute();
};



