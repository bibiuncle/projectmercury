#include "PanelMesh.h"
#include "PanelTexture.h"

PanelMesh::PanelMesh(PanelTexture* tex)
{
	pTex = tex;
}

PanelMesh::~PanelMesh()
{

}

void PanelMesh::Translate(int x, int y)
{
	pVtx.x(0, pVtx.x(0) + x);
	pVtx.x(1, pVtx.x(1) + x);
	pVtx.x(2, pVtx.x(2) + x);
	pVtx.x(3, pVtx.x(3) + x);

	pVtx.y(0, pVtx.y(0) + y);
	pVtx.y(1, pVtx.y(1) + y);
	pVtx.y(2, pVtx.y(2) + y);
	pVtx.y(3, pVtx.y(3) + y);
}

void PanelMesh::Rotate(int x, int y, double deg)
{

}

void PanelMesh::SetTextureCoord(RECT coord, bool resize)
{
	pVtx.tu(0, (float)coord.left / pTex->GetWidth());
	pVtx.tv(0, (float)coord.top / pTex->GetHeight());
	pVtx.tu(1, (float)coord.right / pTex->GetWidth());
	pVtx.tv(1, (float)coord.top / pTex->GetHeight());
	pVtx.tu(2, (float)coord.right / pTex->GetWidth());
	pVtx.tv(2, (float)coord.bottom / pTex->GetHeight());
	pVtx.tu(3, (float)coord.left / pTex->GetWidth());
	pVtx.tv(3, (float)coord.bottom / pTex->GetHeight());

	if (resize)
	{
		pVtx.x(0, 0.0f);
		pVtx.y(0, 0.0f);
		pVtx.x(1, (float)(coord.right - coord.left));
		pVtx.y(1, 0.0f);
		pVtx.x(2, (float)(coord.right - coord.left));
		pVtx.y(2, (float)(coord.bottom - coord.top));
		pVtx.x(3, 0.0f);
		pVtx.y(3, (float)(coord.bottom - coord.top));
	}
}

void PanelMesh::SetWidth(int w)
{
	pVtx.x(1, pVtx.x(0) + w);
	pVtx.x(2, pVtx.x(0) + w);
}

void PanelMesh::SetHeight(int h)
{
	pVtx.y(2, pVtx.y(0) + h);
	pVtx.y(3, pVtx.y(0) + h);
}

float PanelMesh::GetWidth()
{
	return sqrt(pow(pVtx.x(1) - pVtx.x(0), 2) + pow(pVtx.y(1) - pVtx.y(0), 2));
}

float PanelMesh::GetHeight()
{
	return sqrt(pow(pVtx.x(3) - pVtx.x(0), 2) + pow(pVtx.y(3) - pVtx.y(0), 2));
}

PanelTexture* PanelMesh::GetTexture()
{
	return pTex;
}

void PanelMesh::SetMeshData(NTVERTEX* vtx)
{
	pVtx.SetVertexPtr(vtx);
}

SGroup::SGroup()
{
	pVtx = NULL;

	for (int i = 0; i < 4; i++)
	{
		vtx[i].x = 0.0f;
		vtx[i].y = 0.0f;
		vtx[i].tu = 0.0f;
		vtx[i].tv = 0.0f;
	}
}

void SGroup::x(int id, float val)
{
	if (id >= 0 && id < 4)
	{
		vtx[id].x = val;

		if (pVtx)
		{
			pVtx[id].x = val;
		}
	}
}

void SGroup::y(int id, float val)
{
	if (id >= 0 && id < 4)
	{
		vtx[id].y = val;

		if (pVtx)
		{
			pVtx[id].y = val;
		}
	}
}

void SGroup::tu(int id, float val)
{
	if (id >= 0 && id < 4)
	{
		vtx[id].tu = val;

		if (pVtx)
		{
			pVtx[id].tu = val;
		}
	}
}

void SGroup::tv(int id, float val)
{
	if (id >= 0 && id < 4)
	{
		vtx[id].tv = val;

		if (pVtx)
		{
			pVtx[id].tv = val;
		}
	}
}

float SGroup::x(int id)
{
	if (id >= 0 && id < 4)
	{
		return vtx[id].x;
	}

	return 0.0f;
}

float SGroup::y(int id)
{
	if (id >= 0 && id < 4)
	{
		return vtx[id].y;
	}

	return 0.0f;
}

float SGroup::tu(int id)
{
	if (id >= 0 && id < 4)
	{
		return vtx[id].tu;
	}

	return 0.0f;
}

float SGroup::tv(int id)
{
	if (id >= 0 && id < 4)
	{
		return vtx[id].tv;
	}

	return 0.0f;
}

void SGroup::set(int id, float x, float y, float tu, float tv)
{
	if (id >= 0 && id < 4)
	{
		vtx[id].x = x;
		vtx[id].y = y;
		vtx[id].tu = tu;
		vtx[id].tv = tv;

		if (pVtx)
		{
			pVtx[id].x = x;
			pVtx[id].y = y;
			pVtx[id].tu = tu;
			pVtx[id].tv = tv;
		}
	}
}

void SGroup::SetVertexPtr(NTVERTEX* ntvtx)
{
	pVtx = ntvtx;

	for (int i = 0; i < 4; i++)
	{
		pVtx[i].x = vtx[i].x;
		pVtx[i].y = vtx[i].y;
		pVtx[i].tu = vtx[i].tu;
		pVtx[i].tv = vtx[i].tv;
	}
}