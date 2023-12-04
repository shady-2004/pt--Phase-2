#pragma once
#include "Action.h"
class ChangeFillColorAcion :
    public Action
{
public:
	ChangeFillColorAcion(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual void Execute();
};

