#include "MenuButton.h"

#include "InputHandler.h"
#include "Vector2D.h"



MenuButton::MenuButton(const LoaderParams* params, void(*callback)()) :
	SDLGameObject(params),
	_callback(callback),
	_state(ButtonState::MouseOut),
	_released(true)
{
	
}

void MenuButton::draw() {
	SDLGameObject::draw();
}

void MenuButton::update() {
	auto mouse = InputHandler::instance().mousePosition();
	float x = mouse.getX();
	float y = mouse.getY();
	if ((x < (position.getX() + w)) && (x > (position.getX())) &&
		(y < (position.getY() + h)) && (y > (position.getY())))
	{
		if (InputHandler::instance().mouseButton(MouseButton::LEFT) && _released) {
			_state = ButtonState::Clicked;
			if (_callback != nullptr)
				_callback();
			_released = false;
		}
		else
			if (!InputHandler::instance().mouseButton(MouseButton::LEFT)) {
				_released = true;
                _state = ButtonState::MouseOver;
			}
	}
	else
		_state = ButtonState::MouseOut;
	frame = (int)_state;
}

void MenuButton::clean() {
	SDLGameObject::clean();
}
