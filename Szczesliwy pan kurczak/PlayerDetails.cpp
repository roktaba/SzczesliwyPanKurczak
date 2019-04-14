#include "PlayerDetails.h"



PlayerDetails::PlayerDetails(sf::RenderWindow &window)
{
	name = "";
	wholeRecord = "Nazwa gracza: ";
	points = 0;
	if (!nameFont.loadFromFile("Fonts/BreeSerif-Regular.otf"))
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
	}

	nameText.setFont(nameFont);
	nameText.setString(wholeRecord);
	nameText.setCharacterSize(30);
	nameText.setFillColor(sf::Color::Red);
	nameText.setPosition(((window.getSize().x - nameText.getGlobalBounds().width) / 2), (((window.getSize().y - nameText.getGlobalBounds().height) / 2) + 170));
	backspaceTime.getDT();
}


PlayerDetails::~PlayerDetails()
{
}

void PlayerDetails::uptadeName(std::string x)
{
	name += x;
	wholeRecord = "Nazwa gracza: " + name;
	nameText.setString(wholeRecord);
}

void PlayerDetails::uptadeNameBackspace()
{
	if ((name.size() > 0) && (backspaceTime.getDT() > 0.1))
	{
		name.erase(name.size() - 1);
		wholeRecord = "Nazwa gracza: " + name;
		nameText.setString(wholeRecord);
		backspaceTime.restartDT();
	}
}

std::string PlayerDetails::getWholeRecord()
{
	return wholeRecord;
}

void PlayerDetails::drawName(sf::RenderWindow & window)
{
	window.draw(nameText);
}

void PlayerDetails::increasePoint()
{
	points++;
}

void PlayerDetails::saveScore()
{
	std::fstream file;
	int number = 0;
	std::string line;
	file.open("highscore.txt", std::ios::in);
	if (!file.good())
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
	}
	while (!file.eof()) 
	{
		std::getline(file, line);
		scoreStrings.push_back(line);
		std::string stringNumber;
		int i = line.size()-1;
		if (i > 4)
		{
			while (!std::isblank(line[i]))
			{
				i--;
			}
			int x = line.size()-1;
			stringNumber.insert(0, line, i+1, x);
			scoreBoard[number] = std::stoi(stringNumber);
		}
		number++;
	}
	file.close();
	file.open("highscore.txt", std::ios::app);
	if (!file.good())
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
	}
	std::string numberString = std::to_string(number);
	std::string pktString = std::to_string(points);
	std::string saveRecord = numberString + ". " + name + "  punktow: " + pktString;
	file << saveRecord << std::endl;
	file.close();
}
