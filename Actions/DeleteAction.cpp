#include "DeleteAction.h"
#include "../ApplicationManager.h"
#include "../Figures/CFigure.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Deleting the selected Figure:");
}

void DeleteAction::Execute()
{
	CFigure* F = pManager->GetSelectedFig();
	if (F == NULL)
		return;

	ReadActionParameters();
	
	F->SetSelected(0);
	//pManager->DeleteFigure(F);
	pManager->UpdateInterface();
}
