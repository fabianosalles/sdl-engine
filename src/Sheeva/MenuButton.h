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
	MenuButton(const LoaderParams*, void (*callback)());

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	ButtonState _state;
	bool _released;
	void(*_callback)();
};