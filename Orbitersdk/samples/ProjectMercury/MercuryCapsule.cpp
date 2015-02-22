#include "MercuryCapsule.h"
#include "PanelManager.h"

MercuryCapsule::MercuryCapsule(OBJHANDLE hVessel, int flightmodel)
:VESSEL3(hVessel, flightmodel)
{
	pPanelManager = new PanelManager(this);
}

MercuryCapsule::~MercuryCapsule()
{
	delete pPanelManager;
}

bool MercuryCapsule::clbkLoadPanel2D(int id, PANELHANDLE hPanel, DWORD viewW, DWORD viewH)
{
	return pPanelManager->LoadPanel2D(id, hPanel, viewW, viewH);
}

bool MercuryCapsule::clbkPanelMouseEvent(int  id, int  event, int  mx, int  my, void *  context)
{
	return pPanelManager->PanelMouseEvent(id, event, mx, my, context);
}

bool MercuryCapsule::clbkPanelRedrawEvent(int  id, int  event, SURFHANDLE  surf, void *  context)
{
	return pPanelManager->PanelRedrawEvent(id, event, surf, context);
}