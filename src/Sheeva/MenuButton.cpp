#include "MenuButton.h"

#include "InputHandler.h"
#include "Vector2D.h"



MenuButton::MenuButton(const LoaderParams* params) :
	SDLGameObject(params),
	state(ButtonState::MouseOut)
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
		state = (InputHandler::instance().mouseButton(MouseButton::LEFT))
			? ButtonState::Clicked
			: ButtonState::MouseOver;
	}
	else
		state = ButtonState::MouseOut;
	frame = (int)state;
}

void MenuButton::clean() {
	SDLGameObject::clean();
}
