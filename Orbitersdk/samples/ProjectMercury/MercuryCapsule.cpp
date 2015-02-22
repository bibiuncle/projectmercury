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