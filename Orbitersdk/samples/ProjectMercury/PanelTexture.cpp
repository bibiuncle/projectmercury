#include "PanelTexture.h"

PanelTexture::PanelTexture(std::string fname, DWORD width, DWORD height)
{
	tex = NULL;
	tex = oapiLoadTexture(fname.c_str());
	if (!tex)
	{
		sprintf(oapiDebugString(), "Failed to load texture %s.", fname);
	}

	this->width = width;
	this->height = height;
	filename = fname;
}

PanelTexture::~PanelTexture()
{
	if (tex)
	{
		oapiReleaseTexture(tex);
	}
}

std::string PanelTexture::GetFilename()
{
	return filename;
}

SURFHANDLE PanelTexture::GetSurfhandle()
{
	return tex;
}

DWORD PanelTexture::GetWidth()
{
	return width;
}

DWORD PanelTexture::GetHeight()
{
	return height;
}

void PanelTexture::DefineCoordinates(std::string id, RECT coord)
{
	if (coordinates.count(id) == 0)
	{
		coordinates[id] = coord;
	}
}

RECT PanelTexture::GetCoordinates(std::string id)
{
	return coordinates[id];
}