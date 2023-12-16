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
}