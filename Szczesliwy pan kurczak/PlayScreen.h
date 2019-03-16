#pragma once
#include <SFML/Graphics.hpp>
#include "WindowEventCheck.h"
#include "Chicken.h"
#include "Egg.h"
#include <array>
#include "DeltaTime.h"
#include "Points.h"

class PlayScreen
{
public:
	PlayScreen();
	~PlayScreen();
	int playLoop(sf::RenderWindow &window);

private: 
	std::array<Egg, 300> littleEggs;
	int eggsCount;
	DeltaTime dtEggPlacing;
	DeltaTime dt;
};

