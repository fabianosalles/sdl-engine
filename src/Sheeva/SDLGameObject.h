#pragma once
#include <SDL.h>
#include "Game.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject {
public:
	SDLGameObject(const LoaderParams* params)
		: GameObject(params),
		  position(params->x, params->y)
	{
		w = params->w;
		h = params->h;
		textureID = params->textureID;
		row = 1;
		frame = 1;
	}

	virtual void draw() {

		TextureManager::instance().drawFrame(
			textureID, 
			(int)position.getX(),
			(int)position.getY(),
			w, h, row, frame,
			Game::instance().renderer());
	}

	virtual void update() {}

	virtual void clean() {}

protected:
	Vector2D position;
	int w, h, row, frame;
	std::string textureID;
};