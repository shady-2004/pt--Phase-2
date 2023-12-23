#include "SoundAction.h"

SoundAction::SoundAction(ApplicationManager* pApp) :Action(pApp)
{
}

void SoundAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage(" Disenable Sound : Sound has been disenabled");
}

void SoundAction::Execute()
{
	ReadActionParameters();
	pManager->setEnableSound(false);
}
