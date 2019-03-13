#include "Chicken.h"



Chicken::Chicken()
{
	if (!chickenTexture.loadFromFile("Textures/kurczak.jpg"))
	{
		MessageBox(0, "Textures not found!", "ERROR", 0);
		return;
	}
	wchickenTexture = &chickenTexture;
	imgHeight = chickenTexture.getSize().y;
	imgWidth = chickenTexture.getSize().x;
	chickenSprite.setTexture(*wchickenTexture);
	chickenSprite.setTextureRect(sf::IntRect(0, 0, imgWidth, imgHeight));
	chickenSprite.setPosition(300, 300);
	chickenSprite.setOrigin(0.5, 0.5);
}


Chicken::~Chicken()
{
}

void Chicken::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(chickenSprite, states);
}