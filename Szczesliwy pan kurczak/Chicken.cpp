#include "Chicken.h"



Chicken::Chicken()
{
	if (!chickenTexture.loadFromFile("Textures/kurczak.png"))
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
	chickenSprite.setScale(0.35f, 0.35f);
	velocity.x = 0;
	velocity.y = 0;
	jumpHeight = 150;
	canJump = true;
	tempPosY = chickenSprite.getPosition().y;
	dt.restartDT();
}


Chicken::~Chicken()
{
}

void Chicken::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(chickenSprite, states);
}

void Chicken::uptade()
{
	if (!canJump)
	{
		velocity.y += 981 * (float)dt.getDT();
		chickenSprite.move(velocity * (float)dt.getDT());
	}
	if (tempPosY < chickenSprite.getPosition().y)
	{
		velocity.x = 0;
		velocity.y = 0;
		canJump = true;
	}
	dt.restartDT();
}

void Chicken::jump()
{
	if (canJump)
	{
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		canJump = false;
		velocity.x = 70;
		tempPosY = chickenSprite.getPosition().y;
	}
}

sf::Vector2f Chicken::getChickenPos()
{
	return sf::Vector2f(chickenSprite.getPosition().x, chickenSprite.getPosition().y);
}
