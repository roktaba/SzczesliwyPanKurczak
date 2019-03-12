#pragma once
#include <SFML/Graphics.hpp>

class WindowEventCheck
{
public:
	WindowEventCheck();
	~WindowEventCheck();
	static void eventChecker(sf::RenderWindow &window);
};

