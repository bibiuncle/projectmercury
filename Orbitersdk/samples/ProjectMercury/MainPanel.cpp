#include "MainPanel.h"
#include "TestElement.h"
#include "PanelMesh.h"
#include "PanelTexture.h"
#include "PanelTextureManager.h"

MainPanel::MainPanel(MercuryCapsule* vessel)
:Panel(vessel)
{
	pBackground = new PanelMesh(PanelTextureManager::GetTexture("DG/dg_panel.dds"));
	pBackground->SetTextureCoord(_R(0, 452, 1280, 1024));
	SetBackgroundMesh(pBackground);

	SetScrollFlags(PANEL_ATTACH_BOTTOM | PANEL_MOVEOUT_BOTTOM);

	test = new TestElement();
	AddPanelElement(test);
}

MainPanel::~MainPanel()
{
	delete pBackground;
	delete test;
}