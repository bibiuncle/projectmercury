#include "MainPanel.h"
#include "TestElement.h"
#include "PanelMesh.h"
#include "PanelTexture.h"
#include "PanelTextureManager.h"

MainPanel::MainPanel(MercuryCapsule* vessel)
:Panel(vessel)
{
	pBackground = new PanelMesh(PanelTextureManager::GetTexture("Panel1.dds"));
	pBackground->SetTextureCoord(_R(0, 572, 2048, 2048));
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