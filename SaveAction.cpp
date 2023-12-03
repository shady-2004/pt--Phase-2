#include "SaveAction.h"
#include "ApplicationManager.h"
#include <fstream>
#include <iostream>

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp) {

}

void SaveAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the name of the file you want to save in: " + filename);
	filename = pIn->GetString(pOut);
	pOut->ClearStatusBar();
}

void SaveAction::Execute() {
	ReadActionParameters();
	ofstream OutFile;
	OutFile.open("Saved Data/"+filename+".txt");
	pManager->SaveAll(OutFile);
	pManager->GetOutput()->PrintMessage("Your file has been saved successfully!");
	OutFile.close();
}