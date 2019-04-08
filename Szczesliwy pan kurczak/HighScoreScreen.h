#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "WindowEventCheck.h"
#include "DeltaTime.h"
#include <array>
#include <iostream>
#include <fstream>

class HighScoreScreen
{
public:
	HighScoreScreen(sf::RenderWindow &window);
	~HighScoreScreen();
	void hSLoop(sf::RenderWindow &window);

private:
	sf::Font hSFont;
	sf::Text hSName;
	sf::Text exitButton;
	std::array<sf::Text, 10> scores;
	DeltaTime dt;
};

