#include "PlayScreen.h"


PlayScreen::PlayScreen()
{
	eggsCount = 0;
	dtEggPlacing.restartDT();
	dt.restartDT();
}


PlayScreen::~PlayScreen()
{
}

int PlayScreen::playLoop(sf::RenderWindow & window)
{
	Chicken chicken;
	Points points(window);
	while (window.isOpen())
	{
		WindowEventCheck::eventChecker(window);
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (dtEggPlacing.getDT() > 0.8))
		{
			chicken.jump();
			littleEggs[eggsCount].setEggPos(chicken.getChickenPos());
			eggsCount++;
			if (eggsCount == 299)
				eggsCount = 0;
			dtEggPlacing.restartDT();
			points.increasePoints();
		}
		//////////////UPTADE///////////
		chicken.uptade(window);
		/////////////DRAW/////////////
		if (dt.getDT() > 0.017)
		{
			window.clear(sf::Color(51, 153, 255));
			for (int i = 0; i < eggsCount; i++)
			{
				window.draw(littleEggs[i]);
			}
			window.draw(chicken);
			window.draw(points);
			window.display();
			dt.restartDT();
		}
	}
	return 0;
}
