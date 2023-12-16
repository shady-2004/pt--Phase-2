#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
class PickByFillColorAction :
    public Action
{
    Point p;
    int NoOfCorrectPicks;
    int NoOfWrongPicks;
    int Fill;
    CFigure* choosedFig;
    int TypeCount;//No of this Type in Application manager array;


public:
    PickByFillColorAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};

