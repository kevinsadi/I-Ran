#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "CountDown.h"

sf::RenderWindow window(sf::VideoMode(1280, 720), "I Ran", sf::Style::Titlebar | sf::Style::Close);
Player* player = new Player();
Countdown* timer = new Countdown();

// Helper functions
bool hasCollided(sf::Transformable a, sf::Transformable b)
{
	sf::IntRect boundingBoxA(int(a.getPosition().x), int(a.getPosition().y), 100, 100);
	sf::IntRect boundingBoxB(int(b.getPosition().x), int(b.getPosition().y), 100, 100);

	return (boundingBoxA.intersects(boundingBoxB));
}

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
	timer->updateTime();

    for (int i = 0; i < timer->objects.size(); i++)
    {
        if (hasCollided(player->sprite, timer->objects[i]))
            timer->objects[i].setPosition(3000, 3000);
    }
}

// All rendering code goes here
void draw()
{
    window.clear();
    window.draw(player->sprite);
	window.draw(timer->text);

    for (int i = 0; i < timer->objects.size(); i++)
    {
        window.draw(timer->objects[i]);
    }

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