#include "SwitchToPlayModeAction.h"
#include "..\ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
//constructor
SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp):Action(pApp)
{
}

 void SwitchToPlayModeAction::ReadActionParameters() 
 {
	 Output* pOut = pManager->GetOutput();
	 Input* pIn = pManager->GetInput();
	   //print a massare of the selected action
	 pOut->PrintMessage("Switch to play mode: Click anywhere");

 }
void SwitchToPlayModeAction::Execute()
{
	ReadActionParameters();
	(pManager->GetOutput())->CreatePlayToolBar();  //create the play mode tool bar
}
