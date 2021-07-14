#include "Player.h"
#include "InputHandler.h"

void Player::update()
{
	frame = int(((SDL_GetTicks() / 100) % 6));
	//accelaration.setX(0.1);
	handleInput();
	SDLGameObject::update();
}

void Player::handleInput()
{
	/*
	if (InputHandler::instance().joysticksInitialized()) {
		int value = InputHandler::instance().joyX(0, 1);
		if (value != 0)
			velocity.setX(1 * value);
	}

	if (InputHandler::instance().mouseButton(LEFT))
		velocity.setX(-1);

	if (InputHandler::instance().mouseButton(RIGHT))
		velocity.setY(1);
	*/
	/*
	Vector2D& mouse = InputHandler::instance().mousePosition();
	velocity = (mouse - position) / 30;
	*/

	if (InputHandler::instance().keyDown(SDL_SCANCODE_LEFT))
		velocity.setX(-2);

	if (InputHandler::instance().keyDown(SDL_SCANCODE_RIGHT))
		velocity.setX(2);
}
