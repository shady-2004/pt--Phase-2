#include "ChangeFigColorAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeFigColorAction::ChangeFigColorAction(ApplicationManager* pApp):Action(pApp)
{
}

void ChangeFigColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	pOut->PrintMessage("Select Draw Color");

	switch (pIn->GetcolorAction(pOut->colorpalette())) //Get Selected Color from pallete
	{
	case CHOOSE_COLOR_RED:
		UI.DrawColor =  RED;
		pOut->PrintMessage("Selected Color : RED ");
		break;
	case CHOOSE_COLOR_BLUE:
		UI.DrawColor = BLUE;
		pOut->PrintMessage("Selected Color : BLUE");
		break;
	case CHOOSE_COLOR_GREEN:
		UI.DrawColor = GREEN;
		pOut->PrintMessage("Selected Color : GREEN ");
		break;
	case CHOOSE_COLOR_ORANGE:
		UI.DrawColor = ORANGE;
		pOut->PrintMessage("Selected Color : ORANGE ");
		break;
	case CHOOSE_COLOR_YELLOW:
		UI.DrawColor = YELLOW;
		pOut->PrintMessage("Selected Color : YELLOW ");
		break;
	case CHOOSE_COLOR_BLACK:
		UI.DrawColor = BLACK;
		pOut->PrintMessage("Selected Color : BLACK ");
		break;
	}
	pOut->closeColorMenu();

}

void ChangeFigColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();//This action needs to read some parameters first

	CFigure*F = pManager->GetSelectedFig();//
	if (F != NULL)//Checks if there is selected figure or not
	{

		F->ChngDrawClr(UI.DrawColor);
		F->SetSelected(0);
	}
}