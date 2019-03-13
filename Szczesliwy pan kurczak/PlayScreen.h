#pragma once
#include <SFML/Graphics.hpp>
#include "WindowEventCheck.h"
#include "Chicken.h"

class PlayScreen
{
public:
	PlayScreen();
	~PlayScreen();
	int playLoop(sf::RenderWindow &window);
};

