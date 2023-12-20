#include "StartRecordingAction.h"
#include "../ApplicationManager.h"


int StartRecordingAction::RecordCount = 0;

StartRecordingAction::StartRecordingAction(ApplicationManager* pApp) : Action(pApp) {

}

void StartRecordingAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pManager->setRecording(true);
	pOut->PrintMessage("Started Recording!");
}

void StartRecordingAction::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	int FigCount = pManager->GetFigCount();
	if (!RecordCount && FigCount) {
		pOut->PrintMessage("Error! Can only record after a clear all or at the start of the program.");
		pManager->setRecording(false);
		return;
	}
	image* recordList = pManager->GetRecordingList();
	image img;
	if (RecordCount > 20) {
		for (int i = 1; i < 20; i++) {
			image temp = recordList[i];
			recordList[i] = recordList[i - 1];
			recordList[i - 1] = temp;
		}
		RecordCount = 20;
	}
	pOut->screenshotWindow(img);
	recordList[RecordCount++] = img;
}