#include <SFML/Graphics.hpp>

bool hasCollided(sf::RectangleShape a, sf::RectangleShape b)
{
	sf::IntRect boundingBoxA(a.getPosition.x, a.getPosition.y, 100, 100);
	sf::IntRect boundingBoxB(b.getPosition.x, b.getPosition.y, 100, 100);

	return (boundingBoxA.intersects(boundingBoxB));
}