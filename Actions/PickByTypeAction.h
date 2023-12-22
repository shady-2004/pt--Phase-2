#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class PickByTypeAction :
    public Action
{
    Point p;
    int NoOfCorrectPicks;
    int NoOfWrongPicks;
    string FigureType;
    CFigure* choosedFig;
    int TypeCount;//No of this Type in Application manager array;
    bool restart;


public:
    PickByTypeAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};