#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200, MaxActions = 100 };	//Max no of figures , Max no of Actions

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	Action* ActionList[MaxActions];		//List of all actions (Array of pointers)
	int ActionCount;					//Actual number of actions
	
	bool isRecording;
	image RecordingList[20];
	int RecordCount;
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	
	image* GetRecordingList();
	int GetRecordCount();
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	int GetFigCount();						// Getter for figure count

	void setRecording(bool);
	
	void DeleteFigure(CFigure* pFig);
	void DeleteAllFigures();


	void SaveAll(ofstream& OutFile);

	int GetTypeCount(string P);

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window

	//Play mode Functions///
	void resetHidden();
	int getFigFillCount(string x);
	string getFigFillColor(int I);
	string getFigType(int I);
	int getFigCountByFillAndType(string Type, string fill);

	// -- Undo & Redo Functions
	Action** GetActionList();		// Getter for Action list
	int& GetActionCount();			// Getter for Action count
	bool CheckUndoCondition(ActionType action); // checks whether the action is an undo/redo action

	// -- Select Functions
	void SetSelectedFig(CFigure*);			// Setter for Selected Figure
	CFigure* GetSelectedFig();				// Getter for Selected Figure

};
#endif