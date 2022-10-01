//
// Created by Roshan Patel on 9/30/22.
//

#include <SFML/Graphics.hpp>

#ifndef LUDUM51_PLAYER_H
#define LUDUM51_PLAYER_H


class Player {

public:
    Player(); // default constructor
    void update();

    float speed = 5.0f;
    sf::Vector2f position = sf::Vector2f(600, 350);
    sf::RectangleShape sprite; //TODO: Replace with actual sprite.

private:
    void handleInput();

    // Member and function declarations go in header.
    // It is best practice to use variables for input keys.
    sf::Keyboard::Key upKey = sf::Keyboard::W;
    sf::Keyboard::Key downKey = sf::Keyboard::S;
    sf::Keyboard::Key leftKey = sf::Keyboard::A;
    sf::Keyboard::Key rightKey = sf::Keyboard::D;
};


#endif //LUDUM51_PLAYER_H
