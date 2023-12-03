#pragma once
#include "Actions/Action.h"

//Add Circle Action class
class AddHexAction :
    public Action
{
	
	private:
		Point Center; //Center of the hexagon
		GfxInfo HexGfxInfo;
	public:
		AddHexAction(ApplicationManager* pApp);

		//Reads Hexagon parameters
		virtual void ReadActionParameters();

		//Add Hexagon to the ApplicationManager
		virtual void Execute();

};

