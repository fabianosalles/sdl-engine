#include "Player.h"

void Player::load(int x, int y, int w, int h, std::string textureID)
{
	GameObject::load(x, y, w, h, textureID);
}

void Player::draw(SDL_Renderer* renderer)
{
	GameObject::draw(renderer);
}

void Player::update()
{
	x -= 1;
}

void Player::clean()
{
}
