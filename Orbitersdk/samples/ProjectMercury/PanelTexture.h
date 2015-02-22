#pragma once

#include "Orbitersdk.h"
#include <map>

class PanelTexture
{
public:
	PanelTexture(std::string fname, DWORD width, DWORD height);
	virtual ~PanelTexture();

	std::string GetFilename();
	SURFHANDLE GetSurfhandle();
	DWORD GetWidth();
	DWORD GetHeight();

	void DefineCoordinates(std::string id, RECT coord);
	RECT GetCoordinates(std::string id);

private:
	std::string filename;
	SURFHANDLE tex;
	DWORD width;
	DWORD height;
	std::map<std::string, RECT> coordinates;
};