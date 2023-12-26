#include "ExitAction.h"
#include "..\ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
ExitAction::ExitAction(ApplicationManager* pApp):Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int x, y;
	pOut->PrintMessage(" Exiting the program! Click anywhere. ");
	pIn->GetPointClicked(x, y);
	
}

bool ExitAction::Execute()
{
	ReadActionParameters();
	return 1;
}

