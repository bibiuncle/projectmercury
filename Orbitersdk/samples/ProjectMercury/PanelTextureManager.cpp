#include "PanelTextureManager.h"
#include "PanelTexture.h"

std::list<PanelTexture*> PanelTextureManager::textures;

PanelTexture* PanelTextureManager::GetTexture(std::string fname)
{
	fname = "ProjectMercury/" + fname;

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
	textures.push_back(new PanelTexture("ProjectMercury/Panel1.dds", 2048, 2048));
}

void PanelTextureManager::FreeTextures()
{
	for (PanelTexture* tex : textures)
	{
		delete tex;
	}
}