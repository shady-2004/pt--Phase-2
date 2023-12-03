#pragma once
#include "Action.h"

//Add Circle Action class
class AddCircAction :
	public Action

{
private:
	Point Center, Radius; //Center and Radius of the circle
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager* pApp);

	//Reads Circle parameters
	void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();

};

