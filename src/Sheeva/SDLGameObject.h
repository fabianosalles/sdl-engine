#pragma once
#include <SDL.h>
#include "Game.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"

class SDLGameObject : public GameObject {
public:
	SDLGameObject(const LoaderParams* params)
		: GameObject(params) {
		x = params->x;
		y = params->y;
		w = params->w;
		h = params->h;
		textureID = params->textureID;
		row = 1;
		frame = 1;
	}

	virtual void draw() {

		TextureManager::instance().drawFrame(
			textureID, x, y, w, h, row, frame,
			Game::instance().renderer());
	}

	virtual void update() {}

	virtual void clean() {}

protected:
	int x, y, w, h, row, frame;
	std::string textureID;
};