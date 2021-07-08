#pragma once

#include "SDLGameObject.h"
#include "LoaderParams.h"

class Player : public SDLGameObject {
public:
	Player(const LoaderParams* params) : SDLGameObject(params) { };
	
	virtual void draw() { SDLGameObject::draw(); }
	virtual void update() { x -= 1; }
	virtual void clean() { }
};