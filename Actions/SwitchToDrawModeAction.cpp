#include "SwitchToDrawModeAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

SwitchToDrawModeAction::SwitchToDrawModeAction(ApplicationManager* pApp):Action(pApp)
{
}

void SwitchToDrawModeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->resetHidden();
	//print a massage on the status bar
	pOut->PrintMessage("Switch to draw mode: Click anywhere");
}

void SwitchToDrawModeAction::Execute()      // function to execute the action
{
	ReadActionParameters();
	(pManager->GetOutput())->CreateDrawToolBar();    //create the draw mode tool bar
}
