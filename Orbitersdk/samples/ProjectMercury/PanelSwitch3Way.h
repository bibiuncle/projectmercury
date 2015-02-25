#pragma once

class PanelMesh;

#include "PanelElement.h"

enum SPanelSwitch3WayState
{
	LEFT, CENTER, RIGHT
};

class PanelSwitch3Way : public PanelElement
{
public:
	static const int TEXTURE_HEIGHT = 47;
	static const int TEXTURE_WIDTH = 64;

	static const int TEXTURE_LEFT_X = 0;
	static const int TEXTURE_LEFT_Y = 0;
	static const int TEXTURE_CENTER_X = 0;
	static const int TEXTURE_CENTER_Y = 97;
	static const int TEXTURE_RIGHT_X = 0;
	static const int TEXTURE_RIGHT_Y = 48;

	PanelSwitch3Way(int x, int y);
	virtual ~PanelSwitch3Way();

	virtual bool ProcessMouse(int event, int mx, int my);

	virtual std::vector<PanelMesh*> GetPanelMesh();
	virtual std::vector<SPanelArea> GetPanelAreas();

private:
	void SetState(SPanelSwitch3WayState state);

	int x, y;
	SPanelSwitch3WayState state;
	PanelMesh* pMesh;
};