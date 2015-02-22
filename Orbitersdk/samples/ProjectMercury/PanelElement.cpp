#include "PanelElement.h"
#include "PanelMesh.h"

PanelElement::PanelElement()
{

}

PanelElement::~PanelElement()
{

}

void PanelElement::Reset()
{

}

bool PanelElement::Redraw(SURFHANDLE surf)
{
	return false;
}

bool PanelElement::ProcessMouse(int event, int mx, int my)
{
	return false;
}

std::vector<PanelMesh*> PanelElement::GetPanelMesh()
{
	return {};
}