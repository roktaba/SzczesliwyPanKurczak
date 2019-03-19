#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "WindowEventCheck.h"
#include "Chicken.h"
#include "Egg.h"
#include <array>
#include "DeltaTime.h"
#include "Points.h"
#include "PlayerDetails.h"

class PlayScreen
{
public:
	PlayScreen();
	~PlayScreen();
	int playLoop(sf::RenderWindow &window);

private: 
	sf::Sound startsound;
	sf::SoundBuffer startsoundfile;
	sf::Sound eggsound;
	sf::SoundBuffer eggsoundfile;
	sf::Sound backsound;
	sf::SoundBuffer backsoundfile;
	int eggsCount;
	DeltaTime dtEggPlacing;
	DeltaTime dt;
	sf::Texture eggTexture;
	std::array<Egg, 300> littleEggs;
};

