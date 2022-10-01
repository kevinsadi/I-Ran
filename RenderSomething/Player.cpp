//
// Created by Roshan Patel on 9/30/22.
//

#include "Player.h"

Player::Player()
{
    sprite.setSize(sf::Vector2f(100, 100));
}

void Player::update()
{
    sprite.setPosition(position);
    handleInput();
}

void Player::handleInput()
{
    // Store a final vector we use to add to our current position.
    sf::Vector2f movementAmount = sf::Vector2f();

    if (sf::Keyboard::isKeyPressed(leftKey))
        movementAmount.x = -speed;
    else if (sf::Keyboard::isKeyPressed(rightKey))
        movementAmount.x = speed;
    if (sf::Keyboard::isKeyPressed(upKey))
        movementAmount.y = -speed;
    else if (sf::Keyboard::isKeyPressed(downKey))
        movementAmount.y = speed;

    // Handle diagonal movement.
    if (movementAmount.x != 0 && movementAmount.y != 0)
    {
        movementAmount.x *= .7071f;
        movementAmount.y *= .7071f;
    }

    position += movementAmount;
}
