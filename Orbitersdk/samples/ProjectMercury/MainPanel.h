#pragma once

class TestElement;

#include "Panel.h"

class MainPanel : public Panel
{
public:
	MainPanel(MercuryCapsule* vessel);
	virtual ~MainPanel();

private:
	PanelMesh* pBackground;
	TestElement* test;
};