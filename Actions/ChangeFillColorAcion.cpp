#include "ChangeFillColorAcion.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeFillColorAcion::ChangeFillColorAcion(ApplicationManager* pApp):Action(pApp)
{
	PreviousColor = UI.FillColor;
	PreviousState = UI.IsFilled;
}


void ChangeFillColorAcion::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	UI.IsFilled = true;
	pOut->PrintMessage("Select Fill Color");

	switch (pIn->GetcolorAction(pOut->colorpalette())) //Get Selected Color from pallete
	{
	case CHOOSE_COLOR_RED:
		UI.FillColor = RED;
		pOut->PrintMessage("Selected Color : RED ");
		break;
	case CHOOSE_COLOR_BLUE:
		UI.FillColor = BLUE;
		pOut->PrintMessage("Selected Color : BLUE");
		break;
	case CHOOSE_COLOR_GREEN:
		UI.FillColor = GREEN;
		pOut->PrintMessage("Selected Color : GREEN ");
		break;
	case CHOOSE_COLOR_ORANGE:
		UI.FillColor = ORANGE;
		pOut->PrintMessage("Selected Color : ORANGE ");
		break;
	case CHOOSE_COLOR_YELLOW:
		UI.FillColor = YELLOW;
		pOut->PrintMessage("Selected Color : YELLOW ");
		break;
	case CHOOSE_COLOR_BLACK:
		UI.FillColor = BLACK;
		pOut->PrintMessage("Selected Color : BLACK ");
		break;
	}
	pOut->closeColorMenu();

}

void ChangeFillColorAcion::Execute()
{

	SelectedFig = pManager->GetSelectedFig();

	if (SelectedFig == NULL)
		return;

	ReadActionParameters();//This action needs to read some parameters first

	SelectedFig->ChngFillClr(UI.FillColor);

}

void ChangeFillColorAcion::UndoExecution()
{
	if (SelectedFig == NULL)
		return;
	UI.IsFilled = PreviousState;
	SelectedFig->ChngFillClr(PreviousColor);
	pManager->GetOutput()->PrintMessage("Change Fill Color Action Undone");
	
}


void ChangeFillColorAcion::RedoExecution()
{
	if (SelectedFig == NULL)
		return;
	UI.IsFilled = true;
	SelectedFig->ChngFillClr(UI.FillColor);
	pManager->GetOutput()->PrintMessage("Change Fill Color Action Redone");
}
