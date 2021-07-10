#pragma once
#pragma warning( disable : 4244 ) 

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
		  position(params->x, params->y),
		  velocity(0,0),
		  accelaration(0,0)
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

	virtual void update() {
		velocity += accelaration;
		position += velocity;
	}

	virtual void clean() {}

protected:
	Vector2D position;
	Vector2D velocity;
	Vector2D accelaration;
	int w, h, row, frame;
	std::string textureID;
};