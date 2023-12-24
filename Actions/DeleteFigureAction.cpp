#include "DeleteFigureAction.h"
#include "../ApplicationManager.h"
#include "../Figures/CFigure.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteFigureAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(" Delete figure : Figure has been deleted");
	
}

void DeleteFigureAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	temp = pManager->GetSelectedFig();
	if (temp == NULL)
	{
		pOut->PrintMessage(" Error : Please select a figure first ");
		Sleep(1000);
		pOut->ClearStatusBar();
		return;
	}
	ReadActionParameters();
	
	pManager->SetSelectedFig(NULL);
	pManager->DeleteFigure(temp);

}

void DeleteFigureAction::UndoExecution()
{
	if (temp == NULL)
		return;
	pManager->AddFigure(temp);
	pManager->GetOutput()->PrintMessage("Delete Figure Action Undone");
}
