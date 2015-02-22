#include "TestElement.h"
#include "PanelMesh.h"
#include "PanelTexture.h"
#include "PanelTextureManager.h"

TestElement::TestElement()
{
	pMesh = new PanelMesh(PanelTextureManager::GetTexture("DG/dg_panel.dds"));
	pMesh2 = new PanelMesh(PanelTextureManager::GetTexture("DG/dg_panel.dds"));
}

TestElement::~TestElement()
{
	delete pMesh;
	delete pMesh2;
}

void TestElement::Reset()
{
	pMesh->SetTextureCoord(_R(0, 0, 200, 200));
	pMesh2->SetTextureCoord(_R(200, 200, 250, 250));
}

bool TestElement::ProcessMouse(int event, int mx, int my)
{
	pMesh2->SetTextureCoord(_R(100, 100, 300, 300));
	return true;
}

std::vector<PanelMesh*> TestElement::GetPanelMesh()
{
	return { pMesh, pMesh2 };
}

std::vector<SPanelArea> TestElement::GetPanelAreas()
{
	return{ { _R(0, 0, 100, 100), PANEL_REDRAW_USER, PANEL_MOUSE_DOWN } };
}