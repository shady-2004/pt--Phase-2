#include "StopRecordingAction.h"
#include "../ApplicationManager.h"
#include <iostream>

StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) : Action(pApp) {

}

void StopRecordingAction::ReadActionParameters() {
}

void StopRecordingAction::Execute() {
	Output* pOut = pManager->GetOutput();
	int count = pManager->GetRecordCount();
	Action** recordList = pManager->GetRecordingList();

	if (!count) {
		pOut->PrintMessage("You need to start recording first!");
		return;
	}

	pManager->setRecording(false);
	pOut->PrintMessage("Stopped Recording");

	for (int i = 0; i < count; i++) {
		pOut->ClearDrawArea();
		recordList[i]->RedoExecution();
		pManager->UpdateInterface();
		Sleep(1000);
	}
	pOut->PrintMessage("Done");
}