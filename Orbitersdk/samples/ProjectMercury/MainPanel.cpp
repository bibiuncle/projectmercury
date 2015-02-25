#include "MainPanel.h"
#include "PanelMesh.h"
#include "PanelTexture.h"
#include "PanelTextureManager.h"
#include "PanelSwitch3Way.h"

MainPanel::MainPanel(MercuryCapsule* vessel)
:Panel(vessel)
{
	pBackground = new PanelMesh(PanelTextureManager::GetTexture("Panel1.dds"));
	pBackground->SetTextureCoord(_R(0, 572, 2048, 2048), true);
	SetBackgroundMesh(pBackground);

	SetScrollFlags(PANEL_MOVEOUT_BOTTOM | PANEL_MOVEOUT_TOP | PANEL_ATTACH_BOTTOM | PANEL_ATTACH_TOP);

	pSwitchASCSMode = new PanelSwitch3Way(100, 581);
	AddPanelElement(pSwitchASCSMode);
}

MainPanel::~MainPanel()
{
	delete pBackground;
	delete pSwitchASCSMode;
}