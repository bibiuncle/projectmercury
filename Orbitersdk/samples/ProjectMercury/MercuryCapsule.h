#pragma once

class PanelManager;

#include "Orbitersdk.h"

class MercuryCapsule : public VESSEL3
{
public:
	MercuryCapsule(OBJHANDLE hVessel, int flightmodel);
	virtual ~MercuryCapsule();

	virtual bool clbkLoadPanel2D(int id, PANELHANDLE hPanel, DWORD viewW, DWORD viewH);

private:
	PanelManager* pPanelManager;
};