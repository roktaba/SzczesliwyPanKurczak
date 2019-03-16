#include <SFML/Graphics.hpp>
#include "WindowResolution.h"
#include "GameMenu.h"
#include "WindowEventCheck.h"
#include "PlayScreen.h"

int main()
{
	WindowResolution resolution;
	sf::RenderWindow window(sf::VideoMode(resolution.getScreenWidth(), resolution.getScreenHeight()), "Sczesliwy pan kurczak", sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);
	int gameStatus = 1; //0-EXIT, 1-MENU, 2-GAME
	while (window.isOpen())
	{
		WindowEventCheck::eventChecker(window);
		switch (gameStatus)
		{
		case 0:
		{
			window.close();
			break;
		}
		case 1:
		{
			GameMenu menu(window);
			gameStatus = menu.menuLoop(window);
			break;
		}
		case 2:
		{
			PlayScreen playGame;
			gameStatus = playGame.playLoop(window);
			break;
		}
		default:
			break;
		}
	}
	return 0;
}