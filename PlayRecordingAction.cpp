#include "PlayRecordingAction.h"

PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp) :Action(pApp)
{
}

void PlayRecordingAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(" Play Recording!");
}

void PlayRecordingAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	int count = pManager->GetRecordCount();
	image* recordList = pManager->GetRecordingList();
	for (int i = 1; i <= count; i++) {
		pOut->redrawWindow(recordList[i]);
		Sleep(1000);
	}
	pOut->PrintMessage("Done");
}
