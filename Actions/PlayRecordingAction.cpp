#include "PlayRecordingAction.h"

PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp) :Action(pApp)
{
}

void PlayRecordingAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(" Play Recording!");
}

bool PlayRecordingAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	int count = pManager->GetRecordCount();
	if (count == 0)
	{
		pOut->PrintMessage("there is no recording to display ");
		Sleep(1500);
		pOut->ClearStatusBar();
		return 0;
	}
	if (pManager->getRecording())
	{
		pOut->PrintMessage("Error!! Please stop recording first ");
		Sleep(1500);
		pOut->ClearStatusBar();
		return 0;
	}
	image* recordList = pManager->GetRecordingList();
	for (int i = 0; i < count; i++) {
		pOut->redrawWindow(recordList[i]);
		Sleep(1000);
	}
	pOut->PrintMessage("Recording ended ");
	return 1;
}
