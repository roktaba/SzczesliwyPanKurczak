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
	chickenSprite.setScale(0.5f, 0.5f);
	velocity.x = 0;
	velocity.y = 0;
	jumpHeight = 150;
	canJump = true;
	tempPosY = chickenSprite.getPosition().y;
	dt.restartDT();
	srand(time(NULL));
}


Chicken::~Chicken()
{
}

void Chicken::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(chickenSprite, states);
}

void Chicken::uptade(sf::RenderWindow &window)
{
	if (!canJump)
	{
		velocity.y += 981 * (float)dt.getDT();
		chickenSprite.move(velocity * (float)dt.getDT());
		if (tempPosY < chickenSprite.getPosition().y)
		{
			velocity.x = 0;
			velocity.y = 0;
			canJump = true;
			setRandomPos(window);
			tempPosY = chickenSprite.getPosition().y;
		}
	}
	checkWindowBounds(window);
	dt.restartDT();
}

void Chicken::jump()
{
	if (canJump)
	{
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		canJump = false;
		if ((std::rand() % 2 + 1) == 1)
			velocity.x = 70;
		else
			velocity.x = -70;
		tempPosY = chickenSprite.getPosition().y;
	}
}

void Chicken::setRandomPos(sf::RenderWindow &window)
{
	int x = window.getSize().x;
	int y = window.getSize().y;
	chickenSprite.setPosition((std::rand() % x + 1), (std::rand() % y + 1));
	checkWindowBounds(window);
}

void Chicken::setPos(sf::Vector2f pos)
{
	chickenSprite.setPosition(pos);
	tempPosY = chickenSprite.getPosition().y;
}

void Chicken::checkWindowBounds(sf::RenderWindow & window)
{
	if ((chickenSprite.getPosition().x + chickenSprite.getGlobalBounds().width) > (float)window.getSize().x)
		chickenSprite.setPosition(((float)window.getSize().x - chickenSprite.getGlobalBounds().width), chickenSprite.getPosition().y);
	if (chickenSprite.getPosition().x <= 0)
		chickenSprite.setPosition(1, chickenSprite.getPosition().y);
	if ((chickenSprite.getPosition().y + chickenSprite.getGlobalBounds().height) > window.getSize().y)
		chickenSprite.setPosition(chickenSprite.getPosition().x, ((float)window.getSize().y - chickenSprite.getGlobalBounds().height));
	if (chickenSprite.getPosition().y <= 0)
		chickenSprite.setPosition(chickenSprite.getPosition().x, 1);
}

sf::Vector2f Chicken::getChickenPos()
{
	return sf::Vector2f(chickenSprite.getPosition().x, chickenSprite.getPosition().y);
}
