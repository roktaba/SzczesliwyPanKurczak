#include "PlayScreen.h"



PlayScreen::PlayScreen()
{
}


PlayScreen::~PlayScreen()
{
}

int PlayScreen::playLoop(sf::RenderWindow & window)
{
	Chicken chicken;
	while (window.isOpen())
	{
		WindowEventCheck::eventChecker(window);
		window.clear(sf::Color(51, 153, 255));
		window.draw(chicken);
		window.display();
	}
	return 0;
}
