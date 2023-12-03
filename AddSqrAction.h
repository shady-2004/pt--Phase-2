#pragma once
#include"Actions/Action.h"
//Add Square Action class
class AddSqrAction:public Action
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


};

