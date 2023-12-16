#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSqrAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\SaveAction.h"
#include "Actions/LoadAction.h"
#include "Actions\SelectAction.h"
#include "Actions\SwitchToPlayModeAction.h"
#include "Actions\SwitchToDrawModeAction.h"
#include "Actions\ExitAction.h"
#include"Actions/ChangeFigColorAction.h"
#include"Actions/ChangeFillColorAcion.h"
#include "Actions/StartRecordingAction.h"
#include "Actions/StopRecordingAction.h"
#include <fstream>


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	ActionCount = 0;
	RecordCount = 0;
	SelectedFig = NULL;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	for (int i = 0; i < MaxActions; i++)
		ActionList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	ActionCount++;
	if (ActionCount > MaxActions)						// Shifting The array of actions one to the left
	{													// To make space for the new selected action
		for (int i = 0; i < MaxActions-1; i++)
			ActionList[i] = ActionList[i + 1];
		
		ActionCount = MaxActions;
	}
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:

			pAct = new AddRectAction(this);
			break;

		case DRAW_SQUARE:
			pAct = new AddSqrAction(this);
			break;

		case DRAW_CIRCLE:
			pAct = new AddCircAction(this);
			break;

		case DRAW_TRIANGLE:
			pAct = new AddTriAction(this);
			break;

		case DRAW_HEXAGON:
			pAct = new AddHexAction(this);
			break;

		case TO_SAVE_GRAPH:
			pAct = new SaveAction(this);
			break;
		case TO_LOAD_GRAPH:
			pAct = new LoadAction(this);
			break;
		case TO_START_RECORDING:
			pAct = new StartRecordingAction(this);
			break;
		case TO_STOP_RECORDING:
			pAct = new StopRecordingAction(this);
			break;
		case TO_SELECT:
			pAct = new SelectAction(this);
			break;
		case TO_CHANGE_DRAW_COLOR:
			pAct = new ChangeFigColorAction(this);
			break;
		case TO_CHANGE_FILL_COLOR:
			pAct = new ChangeFillColorAcion(this);
			break;
		case TO_PLAY:
			pAct = new SwitchToPlayModeAction(this);
			break;
		case TO_DRAW:
			pAct = new SwitchToDrawModeAction(this);
			break;
		case TO_EXIT:
			///create ExitAction here
			pAct = new ExitAction(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
	}

	if (isRecording && ActType != TO_START_RECORDING && ActType != TO_STOP_RECORDING) {
		RecordCount++;
		if (RecordCount > 20) {
			for (int i = 1; i < 20; i++) {
				image temp = RecordingList[i];
				RecordingList[i] = RecordingList[i - 1];
				RecordingList[i - 1] = temp;
			}
			RecordCount = 20;
		}
		image img;
		GetOutput()->screenshotWindow(img);
		RecordingList[RecordCount - 1] = img;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		ActionList[ActionCount - 1] = pAct;
		ActionList[ActionCount-1]->Execute();//Execute
		//delete pAct;	//You may need to change this line depending to your implementation
		//pAct = NULL;
	}
}

Action** ApplicationManager::GetActionList()
{
	return ActionList;
}

int ApplicationManager::GetActionCount()
{
	return ActionCount;
}

image* ApplicationManager::GetRecordingList() {
	return RecordingList;
}

int ApplicationManager::GetRecordCount() {
	return RecordCount;
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsFound(x,y))
			return FigList[i];
	return NULL;
}

int ApplicationManager::GetFigCount()
{
	return FigCount;
}

void ApplicationManager::SetSelectedFig(CFigure* pFig)
{
	SelectedFig = pFig;
}
CFigure* ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}

void ApplicationManager::setRecording(bool r) {
	isRecording = r;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//							Saving All Figures Function							    //
//==================================================================================//

void ApplicationManager::SaveAll(ofstream &OutFile) {
	OutFile << FigCount << endl;
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
}


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
