#include "PanelTextureManager.h"
#include "PanelTexture.h"

std::list<PanelTexture*> PanelTextureManager::textures;

PanelTexture* PanelTextureManager::GetTexture(std::string fname)
{
	for (PanelTexture* tex : textures)
	{
		if (tex->GetFilename() == fname)
		{
			return tex;
		}
	}

	sprintf(oapiDebugString(), "Could not find texture : %s.", fname);
	return NULL;
}

void PanelTextureManager::LoadTextures()
{
	textures.push_back(new PanelTexture("DG/dg_panel.dds", 2048, 1024));
}

void PanelTextureManager::FreeTextures()
{
	for (PanelTexture* tex : textures)
	{
		delete tex;
	}
}