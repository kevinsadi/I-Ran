//
// Created by Kevin Sadi on 10/1/2022
//

#include <SFML/Graphics.hpp>

#ifndef LUDUM51_COUNTDOWN_H
#define LUDUM51_COUNTDOWN_H


class Countdown
{
public:
	Countdown();

	void updateTime();

	sf::Text text;
	sf::Font font;
	sf::Clock clock;
	float currentTime = 9;
};


#endif  // LUDUM51_COUNTDOWN_H