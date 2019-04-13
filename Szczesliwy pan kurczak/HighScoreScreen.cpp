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
	file.open("highscore.txt", std::ios::in | std::ios::out);
	if (!file.good())
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
	}
	int i = 0;
	while (!file.eof())
	{
		std::getline(file, line);
		scores[i].setString(line);
		scores[i].setFont(hSFont);
		scores[i].setCharacterSize(40);
		scores[i].setFillColor(sf::Color::Red);
		scores[i].setPosition(((window.getSize().x - scores[i].getGlobalBounds().width) / 2.0), (100.0 + (i*70.0)));
		i++;
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
			for (int i = 0; i < 10; i++)
			{
				window.draw(scores[i]);
			}
			window.draw(hSName);
			window.draw(exitButton);
			window.display();
		}
	}
}