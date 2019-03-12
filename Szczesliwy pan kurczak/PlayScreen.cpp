#include "PlayScreen.h"



PlayScreen::PlayScreen()
{
}


PlayScreen::~PlayScreen()
{
}

int PlayScreen::playLoop(sf::RenderWindow & window)
{
	while (window.isOpen())
	{
		window.clear();
		WindowEventCheck::eventChecker(window);
	}
	return 0;
}
