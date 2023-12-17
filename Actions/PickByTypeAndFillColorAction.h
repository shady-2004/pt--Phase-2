#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
class PickByTypeAndFillColorAction :
    public Action
{
    Point p;
    int NoOfCorrectPicks;
    int NoOfWrongPicks;
    DrawMenuItem Figure;//Figure Type to pick
    int Fill;//Fill color to Pick 
    CFigure* choosedFig;
    int TypeCount;//No of this Type in Application manager array;
    bool restart;
public:
    PickByTypeAndFillColorAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();

};

