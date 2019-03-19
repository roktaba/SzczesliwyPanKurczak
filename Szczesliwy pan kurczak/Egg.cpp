#include "Egg.h"



Egg::Egg(sf::Texture &wskegg)
{
/*	if (!eggTexture.loadFromFile("Textures/egg2.png"))
	{
		MessageBox(0, "Textures not found!", "ERROR", 0);
		return;
	}*/
	weggTexture = &wskegg;
	imgHeight = wskegg.getSize().y / 2;
	imgWidth = wskegg.getSize().x / 3;
	eggSprite.setTexture(*weggTexture);
	eggSprite.setTextureRect(sf::IntRect(0, 0, imgWidth, imgHeight));
}

Egg::Egg()
{
}


Egg::~Egg()
{
}

void Egg::setEggPos(sf::Vector2f chickenPos)
{
	eggSprite.setPosition(chickenPos.x + 5, chickenPos.y - 25);
}

void Egg::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(eggSprite, states);
}