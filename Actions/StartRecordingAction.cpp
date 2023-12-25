#include "StartRecordingAction.h"
#include "../ApplicationManager.h"

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
	if (!RecordCount || FigCount) {
		pOut->PrintMessage("Error! Can only record after a clear all or at the start of the program.");
		pManager->setRecording(false);
		return;
	}
}

void StartRecordingAction::Record() {
	/*Action** recordList = pManager->GetRecordingList();
	Output* pOut = pManager->GetOutput();
	RecordCount = pManager->GetRecordCount();
	recordList[RecordCount++] = act;*/
}