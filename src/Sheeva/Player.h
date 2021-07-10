#pragma once
#pragma warning( disable : 4305 ) 

#include "SDLGameObject.h"
#include "LoaderParams.h"

class Player : public SDLGameObject {
public:
	Player(const LoaderParams* params) : SDLGameObject(params) { };
	
	virtual void draw() { SDLGameObject::draw(); }
	virtual void update() { 
		frame = int(((SDL_GetTicks() / 100) % 6));
		accelaration.setX(0.1);
		SDLGameObject::update();
	}
	virtual void clean() { }
};