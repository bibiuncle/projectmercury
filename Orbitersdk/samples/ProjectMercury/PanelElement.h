#pragma once

class PanelMesh;

#include "Orbitersdk.h"
#include <vector>

struct SPanelArea
{
	RECT pos;
	int drawEvent;
	int mouseEvent;
};

class PanelElement
{
public:
	PanelElement();
	virtual ~PanelElement();

	virtual void Reset();
	virtual bool Redraw(SURFHANDLE surf);
	virtual bool ProcessMouse(int event, int mx, int my);

	virtual std::vector<PanelMesh*> GetPanelMesh();
	virtual std::vector<SPanelArea> GetPanelAreas();
};