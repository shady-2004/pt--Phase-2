#pragma once
#include"AddFigureAction.h"
//Add Square Action class
class AddSqrAction:public AddFigureAction
{
	private:
		Point P1; //Square Center
		GfxInfo SqrGfxInfo;
	public:
		AddSqrAction(ApplicationManager* pApp);

		//Reads Square parameters
		virtual void ReadActionParameters();

		//Add Square to the ApplicationManager
		virtual void Execute();

		virtual void UndoExecution();

};

