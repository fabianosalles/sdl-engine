#pragma once

#include "SDLGameObject.h"
#include "LoaderParams.h"

class Enemy : public SDLGameObject {
public:
	Enemy(const LoaderParams* params) : SDLGameObject(params) { };

	virtual void draw() { SDLGameObject::draw(); }
	virtual void update() { y += 1; }
	virtual void clean() {  }
};

