#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "DeltaTime.h"
#include <cmath>
#include <iostream>

class Chicken :public sf::Drawable,
	sf::Transformable
{
public:
	Chicken();
	~Chicken();
	sf::Vector2f getChickenPos();
	void uptade();
	void jump();

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::Sprite chickenSprite;
	sf::Texture chickenTexture;
	sf::Texture *wchickenTexture;
	int imgWidth, imgHeight;
	sf::Vector2f velocity;
	float jumpHeight;
	DeltaTime dt;
	bool canJump;
	float tempPosY;
};

