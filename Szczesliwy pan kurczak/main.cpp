#include <SFML/Graphics.hpp>
#include "WindowResolution.h"

int main()
{
	WindowResolution resolution;
	sf::RenderWindow window(sf::VideoMode(resolution.getScreenWidth(), resolution.getScreenHeight()), "Sczesliwy pan kurczak", sf::Style::Titlebar | sf::Style::Close);

	while (window.isOpen())
	{
		sf::Event windowAction;
		while (window.pollEvent(windowAction))
		{
			switch (windowAction.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}

		}
		window.clear(sf::Color(51, 153, 255));
		window.display();
	}
	return 0;
}