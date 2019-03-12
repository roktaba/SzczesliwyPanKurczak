#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "WindowEventCheck.h"

class GameMenu
{
public:
	GameMenu(sf::RenderWindow &window);
	~GameMenu();
	int menuLoop(sf::RenderWindow &window);

private:
	sf::Font menuFont;
	sf::Text gameName;
	sf::Text playButton;
	sf::Text exitButton;
};

