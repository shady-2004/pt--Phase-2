#include "PickByTypeAndFillColorAction.h"

PickByTypeAndFillColorAction::PickByTypeAndFillColorAction(ApplicationManager* pApp):Action(pApp)
{
	NoOfCorrectPicks = 0;
	NoOfWrongPicks = 0;
	pManager->resetHidden();
	pManager->UpdateInterface();
	restart = 0;
}

void PickByTypeAndFillColorAction::ReadActionParameters()
{

	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(p.x, p.y);
	if ((p.y <= UI.ToolBarHeight)) {
		switch (p.x / (UI.MenuItemWidth + 10)) {
		case FIG_TYPE:
			pManager->ExecuteAction(PICK_FIG_TYPE);
			restart = true;
			break;
		case FIG_FILL_COLOR:
			pManager->ExecuteAction(PICK_FIG_FILL_COLOR);
			restart = true;
			break;
		case FIG_TYPE_AND_FILL_COLOR:
			pManager->ExecuteAction(PICK_FIG_TYPE_AND_FILL_COLOR);
			restart = true;
			break;
		}
	}
}

void PickByTypeAndFillColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	srand(time(0));//// This lines to random a shape
	int Idx = (rand() % pManager->GetFigCount());//Randomed shape idx from fig list
	Figure = pManager->getFigType(Idx);//Get shape type of randomed Idx
	Fill = pManager->getFigFillColor(Idx);//Get shape Color of randomed Idx

	string s1;
	string s2;
	switch (Figure) {
	case ITM_RECT:
		s1="Rectangle";
		break;
	case ITM_SQUARE:
		s1 = "Square";
		break;
	case ITM_TRIANGLE:
		s1 = "Triangle";
		break;
	case ITM_HEXAGON:
		s1 = "Hexagon";
		break;
	case ITM_CIRCLE:
		s1 = "Circle";
		break;
	}

	switch (Fill) {
	case COLOR_RED:
		s2 = "Red";
		break;
	case COLOR_BLUE:
		s2 = "Blue";
		break;
	case COLOR_GREEN:
		s2 = "Green";
		break;
	case COLOR_ORANGE:
		s2 = "Orange";
		break;
	case COLOR_YELLOW:
		s2 = "Yellow";
		break;
	case COLOR_BLACK:
		s2 = "Black";
		break;
	case 10:
		s2 = "Non FIlled";
		break;
	}
	pOut->PrintMessage("Pick By figure type & Fill color : " + s1+" & " + s2);

	TypeCount = (pManager->getFigCountByFillAndType(Figure, Fill));

	while (1) {
		ReadActionParameters();
		if (restart)return;
		choosedFig = pManager->GetFigure(p.x, p.y);
		if (choosedFig != NULL) {
			if (Fill == (choosedFig->getShapeFillColor())&&Figure== (choosedFig->getShapeType())) {
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
	pOut->PrintMessage("Final Grade:  Correct Picks : " + to_string(NoOfCorrectPicks) + "   ""Wrong Picks : " + to_string(NoOfWrongPicks));
}
