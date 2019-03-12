#pragma once
#include <SFML/Graphics.hpp>
#include "WindowEventCheck.h"

class PlayScreen
{
public:
	PlayScreen();
	~PlayScreen();
	int playLoop(sf::RenderWindow &window);
};

