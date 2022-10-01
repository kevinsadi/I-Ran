#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

sf::RenderWindow window(sf::VideoMode(1280, 720), "I Ran");
Player* player = new Player();

// All initialization goes here
void start()
{
    // Note: We do not need a delta time because most computers are fast enough to render this at 60fps.
    // If a computer somehow renders it below 60, the code will start breaking.
    window.setFramerateLimit(60);
}

// All update logic goes here
void update()
{
    player->update();
}

// All rendering code goes here
int draw()
{
    window.clear();
    window.draw(player->sprite);
    window.display();
}

// You should not need to touch this.
int main()
{
    start(); // Executed once

    while (window.isOpen())
    {
        // Window management (no openGL pain)
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
        update();
        draw();
    }

    return 0;
}