#include "StopRecordingAction.h"
#include "../ApplicationManager.h"
#include <iostream>

StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) : Action(pApp) {

}

void StopRecordingAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pManager->setRecording(false);
	pOut->PrintMessage("Recording stopped!");
}

void StopRecordingAction::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
}