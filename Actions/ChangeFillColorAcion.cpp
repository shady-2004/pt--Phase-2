#include "ChangeFillColorAcion.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeFillColorAcion::ChangeFillColorAcion(ApplicationManager* pApp):Action(pApp)
{
}


void ChangeFillColorAcion::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


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
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();//This action needs to read some parameters first

	CFigure* F = pManager->GetSelectedFig();//
	if (F != NULL)//Checks if there is selected figure or not
	{
		F->ChngFillClr(UI.FillColor);
		F->SetSelected(0);
		pManager->UpdateInterface();
	}
}
