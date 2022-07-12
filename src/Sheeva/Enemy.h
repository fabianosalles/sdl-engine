#pragma once

#include "SDLGameObject.h"
#include "LoaderParams.h"

using namespace std;

class Enemy : public SDLGameObject {
public:
	Enemy(const LoaderParams* params);
	virtual void draw();
	virtual void update();
	virtual void clean();
};

