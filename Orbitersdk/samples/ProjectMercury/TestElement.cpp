#include "TestElement.h"
#include "PanelMesh.h"
#include "PanelTexture.h"
#include "PanelTextureManager.h"

TestElement::TestElement()
{
	pMesh = new PanelMesh(PanelTextureManager::GetTexture("Panel1.dds"));
	pMesh->SetTextureCoord(_R(0, 0, 64, 47));
	//pMesh2 = new PanelMesh(PanelTextureManager::GetTexture("DG/dg_panel.dds"));
}

TestElement::~TestElement()
{
	delete pMesh;
	//delete pMesh2;
}

void TestElement::Reset()
{
	//pMesh->SetTextureCoord(_R(0, 0, 200, 200));
	//pMesh2->SetTextureCoord(_R(200, 200, 250, 250));
}

bool TestElement::ProcessMouse(int event, int mx, int my)
{
	pMesh->SetTextureCoord(_R(0, 47, 64, 94));
	return true;
}

std::vector<PanelMesh*> TestElement::GetPanelMesh()
{
	return { pMesh };
}

std::vector<SPanelArea> TestElement::GetPanelAreas()
{
	return{ { _R(0, 0, 100, 100), PANEL_REDRAW_USER, PANEL_MOUSE_DOWN } };
}