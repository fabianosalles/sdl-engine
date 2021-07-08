#include "Enemy.h"
#include "TextureManager.h"

void Enemy::load(int x, int y, int w, int h, std::string textureID)
{
	GameObject::load(x, y, w, h, textureID);
}

void Enemy::draw(SDL_Renderer* renderer)
{
	GameObject::draw(renderer);
}

void Enemy::update()
{
	y += 1;
	x += 1;

	frame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{
}
