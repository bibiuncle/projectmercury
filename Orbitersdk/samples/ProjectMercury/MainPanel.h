#pragma once

class PanelSwitch3Way;

#include "Panel.h"

class MainPanel : public Panel
{
public:
	MainPanel(MercuryCapsule* vessel);
	virtual ~MainPanel();

private:
	PanelMesh* pBackground;
	PanelSwitch3Way* pSwitchASCSMode;
};