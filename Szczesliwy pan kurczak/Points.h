#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <sstream>

class Points :public sf::Drawable,
	sf::Transformable
{
public:
	Points(sf::RenderWindow &window);
	~Points();
	void increasePoints();

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::Text eggPoints;
	std::string pktString;
	sf::Font pointsFont;
	int pkt;
};

