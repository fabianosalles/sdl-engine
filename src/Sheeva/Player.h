#pragma once
#pragma warning( disable : 4305 ) 

#include "SDLGameObject.h"
#include "LoaderParams.h"

class Player : public SDLGameObject {
public:
	Player(const LoaderParams* params) : SDLGameObject(params) { };
	
	virtual void draw() { SDLGameObject::draw(); }
	virtual void update();
	virtual void clean() { }

private:
	void handleInput();
};