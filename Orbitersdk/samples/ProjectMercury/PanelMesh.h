#pragma once

class PanelTexture;

#include "Orbitersdk.h"

struct SVertices
{
	float x, y, tu, tv;
};

class SGroup
{
public:
	SGroup();

	void x(int id, float val);
	void y(int id, float val);
	void tu(int id, float val);
	void tv(int id, float val);

	float x(int id);
	float y(int id);
	float tu(int id);
	float tv(int id);

	void set(int id, float x, float y, float tu, float tv);

	void SetVertexPtr(NTVERTEX* ntvtx);

private:
	NTVERTEX* pVtx;
	SVertices vtx[4];
};

class PanelMesh
{
public:
	PanelMesh(PanelTexture* tex);
	virtual ~PanelMesh();

	void Translate(int x, int y);
	void Rotate(int x, int y, double deg);
	void SetTextureCoord(RECT coord, bool resize = false);
	void SetWidth(int w);
	void SetHeight(int h);
	float GetWidth();
	float GetHeight();

	PanelTexture* GetTexture();
	void SetMeshData(NTVERTEX* vtx);

private:
	PanelTexture* pTex;
	SGroup pVtx;
};