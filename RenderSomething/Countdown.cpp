#include "CountDown.h"
#include <iostream>
#include <stdlib.h>
#include <string>

Countdown::Countdown()
{
	if (!font.loadFromFile("Assets/fonts/BebasNeue-Regular.ttf"))
		std::cout << "Font path not found within Countdown" << std::endl;
	text.setFont(font);
	text.setString(std::to_string(int(currentTime)));
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(1200, 50));
}

void Countdown::updateTime()
{
	sf::Time timeDelta = clock.getElapsedTime();
	currentTime -= timeDelta.asSeconds() / 1000;

	// check for 0 and reset the time
	if (currentTime < 0)
	{
		currentTime = 9.99;
		spawnObject();
	}

	text.setString(std::to_string(int(currentTime)));
}

void Countdown::spawnObject()
{
	object.setSize(sf::Vector2f(100, 100));

	int x = rand() % 1000;
	int y = rand() % 600;
	object.setPosition(sf::Vector2f(x, y));
}