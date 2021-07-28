#include "Player.h"
#include "InputHandler.h"
#include "Vector2D.h"

void Player::update()
{
	frame = int(((SDL_GetTicks() / 100) % 5));
	handleInput();
	SDLGameObject::update();
}

void Player::handleInput()
{
	auto target = InputHandler::instance().mousePosition();
	velocity = (target - position) / 50;
}
