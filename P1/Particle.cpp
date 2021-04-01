#include "Particle.h"

Particle::Particle()
{
}

Particle::~Particle()
{
}

void Particle::cut(D3DXVECTOR2 startPosition, int width, int height)
{
	isInUse = true;
	position = startPosition;
	int angle = rand() % 360;

	cut_rect.left = rand() % (width - 16);
	cut_rect.top = rand() % (height - 16);
	cut_rect.right = cut_rect.left + 16;
	cut_rect.bottom = cut_rect.top + 16;

	position.x += cut_rect.left;
	position.y += cut_rect.top;

	D3DXVECTOR2 direction;
	direction.x = sin(angle / 180.0 * 3.142);
	direction.y = -cos(angle / 180.0 * 3.142);
	D3DXVec2Normalize(&direction, &direction);
	alpha = 255;
	velocity = direction * 100;
}

void Particle::update()
{
	if (isInUse) {
		velocity.y += 400 / 60.0f;
		position += (velocity / 60.0f);
		alpha -= (255 / 60.0f);
		alpha = max(alpha, 0);
	}
	else if (position.x > 400 || position.x < 0 || position.y < 0 || position.y > 300) {
		isInUse = false;
	}
		
}

void Particle::draw(LPD3DXSPRITE sprite, LPDIRECT3DTEXTURE9 texture)
{
	if (isInUse) {
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &position);
		sprite->SetTransform(&mat);
		sprite->Draw(texture, &cut_rect, NULL, NULL, D3DCOLOR_ARGB((int)alpha, 255, 255, 255));
	}
}
