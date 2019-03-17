#include "Points.h"



Points::Points(sf::RenderWindow &window)
{
	if (!pointsFont.loadFromFile("Fonts/BreeSerif-Regular.otf"))
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
		return;
	}
	pkt = 0;
	pktString = std::to_string(pkt);
	eggPoints.setString(pktString);
	eggPoints.setFont(pointsFont);
	eggPoints.setFillColor(sf::Color::Red);
	eggPoints.setCharacterSize(70);
	eggPoints.setPosition((float)window.getSize().x - 100.0f, 20.0f);
}


Points::~Points()
{
}

void Points::increasePoints()
{
	pkt++;
	pktString = std::to_string(pkt);
	eggPoints.setString(pktString);
}

void Points::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(eggPoints, states);
}