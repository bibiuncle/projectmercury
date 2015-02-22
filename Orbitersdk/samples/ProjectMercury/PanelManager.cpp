#include "PanelManager.h"
#include "MainPanel.h"

PanelManager::PanelManager(MercuryCapsule* vessel)
:VesselComponent(vessel)
{
	pMainPanel = new MainPanel(pVessel);
}

PanelManager::~PanelManager()
{
	delete pMainPanel;
}

bool PanelManager::LoadPanel2D(int id, PANELHANDLE hPanel, DWORD viewW, DWORD viewH)
{
	pMainPanel->LoadPanel(hPanel, viewW, viewH);
	return true;
}

bool PanelManager::PanelMouseEvent(int id, int event, int mx, int my, void* context)
{
	return false;
}

bool PanelManager::PanelRedrawEvent(int id, int event, SURFHANDLE surf, void* context)
{
	return false;
}