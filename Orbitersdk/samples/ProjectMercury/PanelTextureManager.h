#pragma once

class PanelTexture;

#include <list>

class PanelTextureManager
{
public:
	static PanelTexture* GetTexture(std::string fname);
	static void LoadTextures();
	static void FreeTextures();

private:
	static std::list<PanelTexture*> textures;
};