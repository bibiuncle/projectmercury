#include "PanelSwitch3Way.h"
#include "PanelTextureManager.h"
#include "PanelMesh.h"

PanelSwitch3Way::PanelSwitch3Way(int x, int y)
{
	this->x = x;
	this->y = y;
	pMesh = new PanelMesh(PanelTextureManager::GetTexture("Panel1.dds"));

	pMesh->Translate(x, y);
	pMesh->SetWidth(TEXTURE_WIDTH);
	pMesh->SetHeight(TEXTURE_HEIGHT);
	SetState(LEFT);
}

PanelSwitch3Way::~PanelSwitch3Way()
{
	delete pMesh;
}

bool PanelSwitch3Way::ProcessMouse(int event, int mx, int my)
{
	bool result = false;

	if ((float)mx / TEXTURE_WIDTH < 0.5f)
	{
		if (state == CENTER)
		{
			SetState(LEFT);
			result = true;
		}

		else if (state == RIGHT)
		{
			SetState(CENTER);
			result = true;
		}
	}

	else
	{
		if (state == CENTER)
		{
			SetState(RIGHT);
			result = true;
		}

		else if (state == LEFT)
		{
			SetState(CENTER);
			result = true;
		}
	}
	
	return result;
}

void PanelSwitch3Way::SetState(SPanelSwitch3WayState state)
{
	this->state = state;

	switch (this->state)
	{
	case LEFT:
		pMesh->SetTextureCoord(_R(TEXTURE_LEFT_X, TEXTURE_LEFT_Y, TEXTURE_LEFT_X + TEXTURE_WIDTH, TEXTURE_LEFT_Y + TEXTURE_HEIGHT));
		break;
		
	case CENTER:
		pMesh->SetTextureCoord(_R(TEXTURE_CENTER_X, TEXTURE_CENTER_Y, TEXTURE_CENTER_X + TEXTURE_WIDTH, TEXTURE_CENTER_Y + TEXTURE_HEIGHT));
		break;

	case RIGHT:
		pMesh->SetTextureCoord(_R(TEXTURE_RIGHT_X, TEXTURE_RIGHT_Y, TEXTURE_RIGHT_X + TEXTURE_WIDTH, TEXTURE_RIGHT_Y + TEXTURE_HEIGHT));
		break;
	}
}

std::vector<PanelMesh*> PanelSwitch3Way::GetPanelMesh()
{
	return{ pMesh };
}

std::vector<SPanelArea> PanelSwitch3Way::GetPanelAreas()
{
	return{ { _R(x, y, x + TEXTURE_WIDTH, y + TEXTURE_HEIGHT), PANEL_REDRAW_USER, PANEL_MOUSE_DOWN } };
}