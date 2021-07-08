#include "GameObject.h"
#include "TextureManager.h"

void GameObject::draw(SDL_Renderer* renderer)
{
	TextureManager::instance().drawFrame(textureID, x, y, w, h, row, frame, renderer);
}

void GameObject::update()
{
	x += 1;
}

void GameObject::load(int x, int y, int w, int h, std::string textureID)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->textureID = textureID;

	row = 1;
	frame = 1;
}