#include "ClearAllAction.h"
#include "../ApplicationManager.h"
#include "UndoAction.h"
#include "RedoAction.h"

ClearAllAction::ClearAllAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ClearAllAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Clear All");
	pOut->CreateDrawToolBar();
}

bool ClearAllAction::Execute()
{
	ReadActionParameters();

	// Reverting Changes of UI info
	UI.DrawColor = BLUE;
	UI.FillColor = GREEN;
	UI.IsFilled = false;

	// Deleting ALl Figures
	pManager->DeleteAllFigures();
	//Setting the selected figure to NULL
	pManager->SetSelectedFig(NULL);


	// Deleting undo & redo history
	Action** ActionList = pManager->GetActionList();
	int &ActionCount = pManager->GetActionCount();

	for (int i = 0; i < ActionCount; i++)
	{
		delete ActionList[i];
		ActionList[i] = NULL;
	}
	ActionCount = 0;
	UndoAction::UndoCount = 0;
	RedoAction::RedoCount = 0;

	// Deleting Record history
	image* recordList = pManager->GetRecordingList();
	int RecordCount = pManager->GetRecordCount();


	return 1;

}
