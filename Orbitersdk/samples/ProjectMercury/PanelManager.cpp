#include "PanelManager.h"
#include "MainPanel.h"

PanelManager::PanelManager(MercuryCapsule* vessel)
:VesselComponent(vessel)
{
	pCurrentPanel = NULL;
	pMainPanel = new MainPanel(pVessel);
}

PanelManager::~PanelManager()
{
	delete pMainPanel;
}

bool PanelManager::LoadPanel2D(int id, PANELHANDLE hPanel, DWORD viewW, DWORD viewH)
{
	pMainPanel->LoadPanel(hPanel, viewW, viewH);
	pCurrentPanel = pMainPanel;
	return true;
}

bool PanelManager::PanelMouseEvent(int id, int event, int mx, int my, void* context)
{
	bool result = false;

	if (pCurrentPanel)
	{
		pCurrentPanel->MouseEvent(id, event, mx, my, context);
	}

	return result;
}

bool PanelManager::PanelRedrawEvent(int id, int event, SURFHANDLE surf, void* context)
{
	bool result = false;

	if (pCurrentPanel)
	{
		pCurrentPanel->RedrawEvent(id, event, surf, context);
	}

	return result;
}