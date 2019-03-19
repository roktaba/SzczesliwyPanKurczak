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
		return;
	}

	nameText.setFont(nameFont);
	nameText.setString(wholeRecord);
	nameText.setCharacterSize(30);
	nameText.setFillColor(sf::Color::Red);
	nameText.setPosition(((window.getSize().x - nameText.getGlobalBounds().width) / 2), (((window.getSize().y - nameText.getGlobalBounds().height) / 2) + 170));
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
	name.erase(name.size() - 1);
	wholeRecord = "Nazwa gracza: " + name;
	nameText.setString(wholeRecord);
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
