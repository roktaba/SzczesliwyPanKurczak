#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>

class Egg :public sf::Drawable,
	sf::Transformable
{
public:
	Egg(sf::Texture &wskegg);
	Egg();
	~Egg();
	void setEggPos(sf::Vector2f chickenPos);

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::Sprite eggSprite;
	//sf::Texture eggTexture;
	sf::Texture *weggTexture;
	int imgWidth, imgHeight;
};

