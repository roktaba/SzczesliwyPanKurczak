#pragma once
#include <SFML/Graphics.hpp>

//CLASS FOR WINDOWED MODE//
class WindowEventCheck
{
public:
	WindowEventCheck();
	~WindowEventCheck();
	static void eventChecker(sf::RenderWindow &window);
};

