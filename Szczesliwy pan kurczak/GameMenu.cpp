#include "GameMenu.h"



GameMenu::GameMenu(sf::RenderWindow &window)
{
	if (!menuFont.loadFromFile("Fonts/BreeSerif-Regular.otf"))
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
		return;
	}
	gameName.setFont(menuFont);
	gameName.setString("SZCZESLIWY PAN KURCZAK");
	gameName.setCharacterSize(70);
	gameName.setFillColor(sf::Color::Yellow);
	gameName.setPosition(((window.getSize().x - gameName.getGlobalBounds().width) / 2), 10);
	playButton.setFont(menuFont);
	playButton.setString("START");
	playButton.setCharacterSize(50);
	playButton.setFillColor(sf::Color::White);
	playButton.setPosition(((window.getSize().x - playButton.getGlobalBounds().width) / 2), ((window.getSize().y - playButton.getGlobalBounds().height) / 2));
	exitButton.setFont(menuFont);
	exitButton.setString("WYJSCIE");
	exitButton.setCharacterSize(50);
	exitButton.setFillColor(sf::Color::White);
	exitButton.setPosition(((window.getSize().x - exitButton.getGlobalBounds().width) / 2), (((window.getSize().y - exitButton.getGlobalBounds().height) / 2) + 70));
}


GameMenu::~GameMenu()
{
}

int GameMenu::menuLoop(sf::RenderWindow & window)
{
	bool exit = false;
	bool play = false;
	while (window.isOpen())
	{
		WindowEventCheck::eventChecker(window);
			
		sf::Vector2f mouse(sf::Mouse::getPosition(window));
		if (playButton.getGlobalBounds().contains(mouse))
		{
			playButton.setFillColor(sf::Color::Red);
		}
		else playButton.setFillColor(sf::Color::White);
		if ((playButton.getGlobalBounds().contains(mouse)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
			play = true;
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			play = true;
			break;
		}
		if (exitButton.getGlobalBounds().contains(mouse))
		{
			exitButton.setFillColor(sf::Color::Red);
		}
		else exitButton.setFillColor(sf::Color::White);
		if ((exitButton.getGlobalBounds().contains(mouse)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
			exit = true;
			break;
		}
		if (dt.getDT() > 0.017)
		{
			dt.restartDT();
			window.clear(sf::Color(51, 153, 255));
			window.draw(gameName);
			window.draw(playButton);
			window.draw(exitButton);
			window.display();
		}
	}
	if (play)
		return 2;
	if (!window.isOpen())
		exit = true;
	if (exit)
		return 0;
	return 0;
}
