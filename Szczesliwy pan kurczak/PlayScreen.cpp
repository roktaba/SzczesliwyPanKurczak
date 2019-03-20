#include "PlayScreen.h"


PlayScreen::PlayScreen()
{
	if (!eggTexture.loadFromFile("Textures/egg2.png"))
	{
	MessageBox(0, "Textures not found!", "ERROR", 0);
	return;
	}
	eggsCount = 0;
	dtEggPlacing.restartDT();
	dt.restartDT();
	if (!startsoundfile.loadFromFile("Audio/startaudio.wav"))
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
		return;
	}
	startsound.setBuffer(startsoundfile);
	if (!eggsoundfile.loadFromFile("Audio/eggaudio.wav"))
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
		return;
	}
	eggsound.setBuffer(eggsoundfile);
	if (!backsoundfile.loadFromFile("Audio/tlo.wav"))
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
		return;
	}
	backsound.setBuffer(backsoundfile);
}


PlayScreen::~PlayScreen()
{
}

int PlayScreen::playLoop(sf::RenderWindow & window)
{
	std::string test;
	PlayerDetails player1(window);
	int returnValue = 2;
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::TextEntered)&& (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)))
			{
			test = event.text.unicode;
			player1.uptadeName(test);
			}
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			player1.uptadeNameBackspace();
		}
		window.clear(sf::Color(51, 153, 255));
		player1.drawName(window);
		window.display();
	}
	Chicken chicken;
	Points points(window);
	startsound.play();
	while (returnValue == 2)
	{
		WindowEventCheck::eventChecker(window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			returnValue = 1;
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (dtEggPlacing.getDT() > 1))
		{
			chicken.jump();
			eggsound.play();
			Egg egg(eggTexture);
			littleEggs[eggsCount] = egg;
			littleEggs[eggsCount].setEggPos(chicken.getChickenPos());
   			eggsCount++;
			player1.increasePoint();
			if (eggsCount%10 == 0)
				backsound.play();
			if (eggsCount == 299)
				eggsCount = 0;
			dtEggPlacing.restartDT();
			points.increasePoints();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (dtEggPlacing.getDT() > 1))
		{
			sf::Vector2f mouse(sf::Mouse::getPosition(window));
			chicken.jump();
			eggsound.play();
			Egg egg(eggTexture);
			littleEggs[eggsCount] = egg;
			littleEggs[eggsCount].setEggPos(mouse);
			chicken.setPos(mouse);
			player1.increasePoint();
			eggsCount++;
			if (eggsCount % 10 == 0)
				backsound.play();
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
	return returnValue;
}
