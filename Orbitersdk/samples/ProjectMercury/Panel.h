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
	virtual bool MouseEvent(int id, int event, int mx, int my, void* context);
	virtual bool RedrawEvent(int id, int event, SURFHANDLE surf, void* context);

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