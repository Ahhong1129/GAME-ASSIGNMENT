#pragma once
#include"GGraphic.h"
class Particle
{
public:
	Particle();
	~Particle();

	D3DXVECTOR2 position;
	D3DXVECTOR2 velocity;
	D3DXMATRIX mat;
	RECT cut_rect;

	float alpha;
	bool isInUse;
	void cut(D3DXVECTOR2 startPosition, int width, int height);

	void update();
	void draw(LPD3DXSPRITE sprite, LPDIRECT3DTEXTURE9 texture);
};

