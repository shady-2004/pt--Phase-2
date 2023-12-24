#pragma once
#include "Action.h"
class ChangeFillColorAcion :
    public Action
{
	color PreviousColor;
	CFigure* SelectedFig;
	bool PreviousState;
public:
	ChangeFillColorAcion(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual void Execute();

	virtual void UndoExecution();

	virtual void RedoExecution();
};

