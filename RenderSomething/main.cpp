#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "ya boi");
	window.setFramerateLimit(60);

	sf::RectangleShape rect;

	sf::Vector2f charPos = sf::Vector2f(600, 350);

	rect.setPosition(charPos);
	rect.setSize(sf::Vector2f(100, 100));

	float playerSpeed = 5.0f;

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

		// Keyboard Handling
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			charPos.x = charPos.x - playerSpeed;
			rect.setPosition(charPos);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
		{
			charPos.x = charPos.x + playerSpeed;
			rect.setPosition(charPos);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
		{
			charPos.y = charPos.y - playerSpeed;
			rect.setPosition(charPos);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
		{
			charPos.y = charPos.y + playerSpeed;
			rect.setPosition(charPos);
		}


		// render stuff
		window.clear();

		window.draw(rect); // add to buffer

		window.display(); // actually display it. Double buffer.
	}

	return 0;
}