#pragma once

#include "SDLGameObject.h"
#include "LoaderParams.h"

enum ButtonState {
	MouseOut = 0,
	MouseOver = 1,
	Clicked = 2
};

class MenuButton : public SDLGameObject {
public:
	MenuButton(const LoaderParams*);

	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	ButtonState state;
};