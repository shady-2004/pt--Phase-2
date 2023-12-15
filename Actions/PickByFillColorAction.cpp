#include"PickByFillColorAction.h"

PickByFillColorAction::PickByFillColorAction(ApplicationManager* pApp):Action(pApp)
{
	NoOfCorrectPicks = 0;
	NoOfWrongPicks = 0;
	pManager->resetHidden();
	pManager->UpdateInterface();
}

void PickByFillColorAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(p.x, p.y);
}

void PickByFillColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	srand(time(0));//// This lines to random a shape
	Fill = pManager->getFigFillColor((rand() % pManager->GetFigCount()));//Random a shape idx and get its Fill color to make sure it will no random a shape not drawn
	TypeCount = pManager->getFigFillCount(Fill);
	switch (Fill) {
	case COLOR_RED:
		pOut->PrintMessage("Pick By figure fill color : Red");
		break;
	case COLOR_BLUE:
		pOut->PrintMessage("Pick By figure fill color : Blue");
		break;
	case COLOR_GREEN:
		pOut->PrintMessage("Pick By figure fill color : Green");
		break;
	case COLOR_ORANGE:
		pOut->PrintMessage("Pick By figure fill color : Orange");
		break;
	case COLOR_YELLOW:
		pOut->PrintMessage("Pick By figure fill color : Yellow");
		break;
	case COLOR_BLACK:
		pOut->PrintMessage("Pick By figure fill color : Black");
		break;
	case 10:
		pOut->PrintMessage("Pick By figure fill color : Non FIlled");
		break;
	}
	////////////////////////////////////

	while (1) {
		ReadActionParameters();
		choosedFig = pManager->GetFigure(p.x, p.y);
		if (choosedFig != NULL) {
			if (Fill == (choosedFig->getShapeFillColor())) {
				NoOfCorrectPicks++;
			}
			else
				NoOfWrongPicks++;

			choosedFig->setIsHidden(1);
			pOut->ClearDrawArea();
			pManager->UpdateInterface();
			pOut->PrintMessage(" Correct Picks : " + to_string(NoOfCorrectPicks) + "   ""Wrong Picks : " + to_string(NoOfWrongPicks));
		}


		if (NoOfCorrectPicks == TypeCount)
			break;
	}
	pOut->PrintMessage("Final Grade:  Correct Picks : " + to_string(NoOfCorrectPicks) + "   ""Wrong Picks : " + to_string(NoOfWrongPicks));
}
