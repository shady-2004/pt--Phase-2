#pragma once
#include "Actions/Action.h"
class SaveAction : public Action
{
private:
	string filename; //file name of the save file
public:
	SaveAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(); //Read Parameters

	virtual void Execute(); //Saves the figures
};

