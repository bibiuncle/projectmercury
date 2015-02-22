#define ORBITER_MODULE

#include "Orbitersdk.h"
#include "MercuryCapsule.h"
#include "PanelTextureManager.h"

DLLCLBK void InitModule(HINSTANCE hModule)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	PanelTextureManager::LoadTextures();
}

DLLCLBK void ExitModule(HINSTANCE hModule)
{
	PanelTextureManager::FreeTextures();
}

DLLCLBK VESSEL* ovcInit(OBJHANDLE hVessel, int flightmodel)
{
	return new MercuryCapsule(hVessel, flightmodel);
}

DLLCLBK void ovcExit(VESSEL* pVessel)
{
	if (pVessel) delete (MercuryCapsule*)pVessel;
}