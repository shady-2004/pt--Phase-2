#pragma once
#include "Action.h"
class StartRecordingAction : public Action
{
private:
	static int RecordCount;
public:
	StartRecordingAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(); //Read Parameters

	virtual void Execute();
};

