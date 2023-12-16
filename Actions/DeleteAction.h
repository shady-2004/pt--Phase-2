#pragma once
#include "Action.h"
class DeleteAction : public Action
{


public:
	DeleteAction(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual void Execute();

};

