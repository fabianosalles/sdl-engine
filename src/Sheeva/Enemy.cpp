//
// Created by fabiano on 12/07/22.
//

#include "Enemy.h"

Enemy::Enemy(const LoaderParams *params) : SDLGameObject(params) {
    velocity.setY(2);
    velocity.setX(0.001);
}

void Enemy::draw() {
    SDLGameObject::draw();
}

void Enemy::clean() {
    SDLGameObject::clean();
}

void Enemy::update() {
    frame = int(((SDL_GetTicks() / 100) % 5));
    if (position.getY() < 0)
        velocity.setY(2);
    else if (position.getY() > 400)
        velocity.setY(-2);
    SDLGameObject::update();
}

