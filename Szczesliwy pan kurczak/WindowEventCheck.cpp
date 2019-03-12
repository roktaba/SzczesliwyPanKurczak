#include "WindowEventCheck.h"



WindowEventCheck::WindowEventCheck()
{
}


WindowEventCheck::~WindowEventCheck()
{
}

void WindowEventCheck::eventChecker(sf::RenderWindow & window)
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
}

