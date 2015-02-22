#pragma once

class PanelManager;

#include "Orbitersdk.h"

class MercuryCapsule : public VESSEL3
{
public:
	MercuryCapsule(OBJHANDLE hVessel, int flightmodel);
	virtual ~MercuryCapsule();

	virtual bool clbkLoadPanel2D(int id, PANELHANDLE hPanel, DWORD viewW, DWORD viewH);
	virtual bool clbkPanelMouseEvent(int  id, int  event, int  mx, int  my, void *  context);
	virtual bool clbkPanelRedrawEvent(int  id, int  event, SURFHANDLE  surf, void *  context);

private:
	PanelManager* pPanelManager;
};