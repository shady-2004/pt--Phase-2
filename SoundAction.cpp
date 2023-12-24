#include "SoundAction.h"

SoundAction::SoundAction(ApplicationManager* pApp) :Action(pApp)
{
}

void SoundAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getEnableSound())
	{
		pOut->PrintMessage(" Disenable Sound : Sound has been disenabled");
		Sleep(1500);
		pOut->ClearStatusBar();
	}
	else
	{
		pOut->PrintMessage(" Enable Sound : Sound has been enabled");
		Sleep(1500);
		pOut->ClearStatusBar();
	}
}

void SoundAction::Execute()
{
	ReadActionParameters();

	pManager->setEnableSound(!pManager->getEnableSound());
}
