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

	pOut->PrintMessage(" Exit Action : You are about to exit this game ");
}

void ExitAction::Execute()
{
	ReadActionParameters();
}

