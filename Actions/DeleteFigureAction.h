#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
class DeleteFigureAction : public Action
{

	CFigure* temp;
public:
	DeleteFigureAction(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual void Execute();

	virtual void UndoExecution();

	virtual void RedoExecution();
};

