#pragma once
#include "../Figures/CFigure.h"
#include "Action.h"
class AddFigureAction : public Action
{
protected:
	CFigure* F;

public:
	AddFigureAction(ApplicationManager* pApp);

	virtual void UndoExecution();

	virtual void RedoExecution();
};

