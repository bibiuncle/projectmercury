#pragma once

class PanelMesh;
class PanelElement;
class PanelTexture;

#include "Orbitersdk.h"
#include "VesselComponent.h"
#include <vector>
#include <map>

class Panel: public VesselComponent
{
public:
	Panel(MercuryCapsule* vessel);
	virtual ~Panel();

	virtual void LoadPanel(PANELHANDLE hPanel, DWORD viewW, DWORD viewH);

protected:
	void SetBackgroundMesh(PanelMesh* mesh);
	void SetScrollFlags(DWORD flags);
	void AddPanelElement(PanelElement* elem);

private:
	void CreateMesh();
	void GenerateMeshGroups(const std::vector<PanelMesh*> &meshes);

	PANELHANDLE hPanel;
	MESHHANDLE hMesh;
	PanelMesh* pMeshBackground;
	DWORD scrollFlags;
	std::vector<PanelTexture*> pTextures;
	std::vector<PanelElement*> pPanelElements;
};