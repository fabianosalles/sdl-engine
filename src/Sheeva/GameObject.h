#pragma once
#include <iostream>
#include <SDL.h>

class GameObject {
public:
	virtual void load(int x, int y, int w, int h, std::string textureID);
	virtual void draw(SDL_Renderer* renderer);
	virtual void update();
	virtual void clean() { std::cout << "clean game object"; }
protected:
	std::string textureID;
	int x, y, w, h;
	int frame, row;
};