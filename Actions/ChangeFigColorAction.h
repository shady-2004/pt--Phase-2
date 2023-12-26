#pragma once
#include "Action.h"
class ChangeFigColorAction :
	public Action
{
	color UndoColor;
	color RedoColor;
	color Previous_UI_Draw_Color;
	CFigure* SelectedFig;

public:
	ChangeFigColorAction(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual bool Execute();

	virtual void UndoExecution();

	virtual void RedoExecution();
};

