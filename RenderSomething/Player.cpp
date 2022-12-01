//
// Created by Roshan Patel on 9/30/22.
//

#include <iostream>
#include "Player.h"

Player::Player()
{
    if (!texture.loadFromFile("Assets/sprites/character.png"))
        std::cout << "Could not load player texture" << std::endl;

    sprite.setTexture(texture);
}

void Player::update()
{
	handleInput();
    sprite.setPosition(position);
}

void Player::handleInput()
{
	// Store a final vector we use to add to our current position.
	sf::Vector2f movementAmount = sf::Vector2f();

	if (position.x > 0 && sf::Keyboard::isKeyPressed(leftKey))
		movementAmount.x = -speed;
	else if (position.x < 1180 && sf::Keyboard::isKeyPressed(rightKey))
		movementAmount.x = speed;
	if (position.y > 0 && sf::Keyboard::isKeyPressed(upKey))
		movementAmount.y = -speed;
	else if (position.y < 620 && sf::Keyboard::isKeyPressed(downKey))
		movementAmount.y = speed;

	// Handle diagonal movement.
	if (movementAmount.x != 0 && movementAmount.y != 0)
	{
		movementAmount.x *= .7071f;
		movementAmount.y *= .7071f;
	}

	position += movementAmount;
}