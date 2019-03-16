#pragma once
#include <SFML/Graphics.hpp>

class DeltaTime
{
public:
	DeltaTime();
	~DeltaTime();
	double getDT();
	void restartDT();

private:
	sf::Clock deltaTime;
	double dt;
};

