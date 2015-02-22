#pragma once

class MainPanel;

#include "Orbitersdk.h"
#include "VesselComponent.h"

class PanelManager: public VesselComponent
{
public:
	PanelManager(MercuryCapsule* vessel);
	virtual ~PanelManager();

	bool LoadPanel2D(int id, PANELHANDLE hPanel, DWORD viewW, DWORD viewH);
	bool PanelMouseEvent(int id, int event, int mx, int my, void* context);
	bool PanelRedrawEvent(int id, int event, SURFHANDLE surf, void* context);

private:
	MainPanel* pMainPanel;
};