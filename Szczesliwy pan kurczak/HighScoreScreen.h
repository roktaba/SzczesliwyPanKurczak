#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "WindowEventCheck.h"
#include "DeltaTime.h"

class HighScoreScreen
{
public:
	HighScoreScreen(sf::RenderWindow &window);
	~HighScoreScreen();
};

