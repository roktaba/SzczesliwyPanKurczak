#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>

class Chicken :public sf::Drawable,
	sf::Transformable
{
public:
	Chicken();
	~Chicken();

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::Sprite chickenSprite;
	sf::Texture chickenTexture;
	sf::Texture *wchickenTexture;
	float imgWidth, imgHeight;
};

