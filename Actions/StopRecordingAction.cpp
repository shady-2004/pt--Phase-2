#include "StopRecordingAction.h"
#include "../ApplicationManager.h"

StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) : Action(pApp) {

}

void StopRecordingAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pManager->setRecording(false);
	pOut->PrintMessage("Recording stopped now playing");
}

void StopRecordingAction::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	int count = pManager->GetRecordCount();
	image* recordList = pManager->GetRecordingList();
	for (int i = 0; i < count; i++) {
		pOut->redrawWindow(recordList[i]);
		Sleep(1000);
	}
	pOut->PrintMessage("Done");
}