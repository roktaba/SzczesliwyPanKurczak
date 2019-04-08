#include "HighScoreScreen.h"



HighScoreScreen::HighScoreScreen(sf::RenderWindow &window)
{
	if (!hSFont.loadFromFile("Fonts/BreeSerif-Regular.otf"))
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
	}
	hSName.setFont(hSFont);
	hSName.setString("WYNIKI");
	hSName.setCharacterSize(50);
	hSName.setFillColor(sf::Color::Yellow);
	hSName.setPosition(((window.getSize().x - hSName.getGlobalBounds().width) / 2), 10);
	exitButton.setFont(hSFont);
	exitButton.setString("WYJSCIE");
	exitButton.setCharacterSize(40);
	exitButton.setFillColor(sf::Color::Red);
	exitButton.setPosition(((window.getSize().x - hSName.getGlobalBounds().width) / 2.0), (window.getSize().y - 100));
}


HighScoreScreen::~HighScoreScreen()
{
}

void HighScoreScreen::hSLoop(sf::RenderWindow & window)
{
	std::fstream file;
	std::string line;
	file.open("highscore.txt", std::ios::in);
	if (!file.good())
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
	}
	while (!file.eof())
	{
		int i = 0;
		std::getline(file, line);
		scores[i].setString(line);
	}
	file.close();
	bool loop = true;
	while (loop)
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(window));
		if (exitButton.getGlobalBounds().contains(mouse))
		{
			exitButton.setFillColor(sf::Color::Red);
		}
		else exitButton.setFillColor(sf::Color::White);
		if ((exitButton.getGlobalBounds().contains(mouse)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
			loop = false;
		}
		if (dt.getDT() > 0.017)
		{
			dt.restartDT();
			window.clear(sf::Color(51, 153, 255));
			window.draw(hSName);
			window.draw(exitButton);
			window.display();
		}
	}
}
