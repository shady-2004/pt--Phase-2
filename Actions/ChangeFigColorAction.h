#pragma once
#include "Action.h"
class ChangeFigColorAction :
	public Action
{

public:
	ChangeFigColorAction(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual void Execute();
};

