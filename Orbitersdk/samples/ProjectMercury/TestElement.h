#pragma once

class PanelMesh;

#include "PanelElement.h"

class TestElement : public PanelElement
{
public:
	TestElement();
	virtual ~TestElement();

	virtual void Reset();
	//virtual bool Redraw(SURFHANDLE surf);
	//virtual bool ProcessMouse(int event, int mx, int my);

	virtual std::vector<PanelMesh*> GetPanelMesh();

private:
	PanelMesh* pMesh;
	PanelMesh* pMesh2;
};