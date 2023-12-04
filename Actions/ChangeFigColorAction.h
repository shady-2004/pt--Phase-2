#pragma once
#include "Action.h"
class ChangeFigColorAction :
	public Action
{
private:


public:
	ChangeFigColorAction(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual void Execute();
};

