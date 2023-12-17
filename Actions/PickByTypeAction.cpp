#include "PickByTypeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<stdlib.h>
#include<Windows.h>
#include<cstring>

PickByTypeAction::PickByTypeAction(ApplicationManager* pApp) :Action(pApp)
{
	NoOfCorrectPicks = 0;
	NoOfWrongPicks = 0;
	pManager->resetHidden();
	pManager->UpdateInterface();
	restart = false;
}

void PickByTypeAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(p.x, p.y);
	if ((p.x / (UI.MenuItemWidth + 10)) == FIG_TYPE &&p.y<=UI.ToolBarHeight) {
		pManager->ExecuteAction(PICK_FIG_TYPE);
		restart = 1;
	}
}
void PickByTypeAction::Execute() {
	Output* pOut = pManager->GetOutput();
		srand(time(0));//// This lines to random a shape
	Figure = pManager->getFigType((rand() % pManager->GetFigCount()));//Random a shape idx and get its Type to make sure it will no random a shape not drawn
		
	switch (Figure) {
	case ITM_RECT:
		pOut->PrintMessage("Pick By figure type : Rectangle");
		break;
	case ITM_SQUARE:
		pOut->PrintMessage("Pick By figure type : Square");
		break;
	case ITM_TRIANGLE:
		pOut->PrintMessage("Pick By figure type : Triangle");
		break;
	case ITM_HEXAGON:
		pOut->PrintMessage("Pick By figure type : Hexagon");
		break;
	case ITM_CIRCLE:
		pOut->PrintMessage("Pick By figure type : Circle");
		break;
	}

	////////////////////////////////////
	TypeCount = pManager->GetTypeCount(Figure);

	while (1) {
		ReadActionParameters();
		if (restart)return;
		choosedFig = pManager->GetFigure(p.x, p.y);

		if (choosedFig != NULL) {
			if (Figure == (choosedFig->getShapeType())) {
				NoOfCorrectPicks++;
			}
			else
				NoOfWrongPicks++;

			choosedFig->SetHidden(1);
			pOut->ClearDrawArea();
			pManager->UpdateInterface();
			pOut->PrintMessage(" Correct Picks : " + to_string(NoOfCorrectPicks) + "   ""Wrong Picks : " + to_string(NoOfWrongPicks));
		}


		if (NoOfCorrectPicks == TypeCount)
			break;
	}
	pOut->PrintMessage( "Final Grade:  Correct Picks : " + to_string(NoOfCorrectPicks) + "   ""Wrong Picks : " + to_string(NoOfWrongPicks));
}
	
