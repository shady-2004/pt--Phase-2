#include "SelectAction.h"
#include"../GUI/Input.h"
#include"../GUI/Output.h"
#include"../ApplicationManager.h"
SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp)
{

}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on a figure:");
	pIn->GetPointClicked(point.x, point.y);
	SelectedFig = pManager->GetFigure(point.x, point.y);
	
}

void SelectAction::Execute()
{
	ReadActionParameters();
	id = pManager->GetActionCount();

	if (pManager->GetSelectedFig() != NULL)			//This means that there is a figure previously selected

	{
		if (pManager->GetSelectedFig() == SelectedFig)	//Case 1: User clicks on the same selected figure
			SelectedFig->SetSelected(0);

			
		else if (SelectedFig == NULL)					//Case 2: User clicks on an empty area
			return;	


		else											//Case 3: User clicks on a different figure
		{
			pManager->GetSelectedFig()->SetSelected(0);
			SelectedFig->SetSelected(1);
			pManager->SetSelectedFig(SelectedFig);
			SelectedFig->Print(pManager->GetOutput());
		}
	}
	else												// This means that this is the first time the user selects a figure
		{
			SelectedFig->SetSelected(1);
			pManager->SetSelectedFig(SelectedFig);
			SelectedFig->Print(pManager->GetOutput());
		}

}

