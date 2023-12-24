#pragma once
#include "Action.h"
class ChangeFigColorAction :
	public Action
{
	color PreviousColor;
	CFigure* SelectedFig;

public:
	ChangeFigColorAction(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual void Execute();

	virtual void UndoExecution();

	virtual void RedoExecution();
};

