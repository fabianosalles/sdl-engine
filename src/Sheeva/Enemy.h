#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	void load(int x, int y, int w, int h, std::string textureID);
	void draw(SDL_Renderer* renderer);
	void update();
	void clean();
};

