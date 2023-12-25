#pragma once

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int id;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool Hidden;
	DrawMenuItem ShapeType;

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	virtual void PrintInfo(Output* pOut) = 0 ;	//print all figure info on the status bar

	virtual bool IsFound(int x, int y) = 0;

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	void SetHidden(bool x);
	bool IsHidden();
	DrawMenuItem getShapeType();
	int getShapeFillColor();

	virtual void Move(int, int ,Output*,Input*) = 0;
	virtual void ReturnFigure() {};

	virtual ~CFigure() = 0;
};
