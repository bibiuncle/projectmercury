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
}

void TestElement::Reset()
{
	pMesh->SetTextureCoord(_R(0, 0, 200, 200));
	pMesh2->SetTextureCoord(_R(200, 200, 250, 250));
}

std::vector<PanelMesh*> TestElement::GetPanelMesh()
{
	return { pMesh, pMesh2 };
	//return{ pMesh2 };
}