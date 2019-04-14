#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <Windows.h>
#include "DeltaTime.h"
#include <fstream>
#include <cctype>
#include <vector>

class PlayerDetails
{
public:
	PlayerDetails(sf::RenderWindow &window);
	~PlayerDetails();
	void uptadeName(std::string x);
	void uptadeNameBackspace();
	std::string getWholeRecord();
	void drawName(sf::RenderWindow &window);
	void increasePoint();
	void saveScore();

private:
	std::string name;
	int points;
	std::string wholeRecord;
	sf::Font nameFont;
	sf::Text nameText;
	DeltaTime backspaceTime;
	int scoreBoard[10] = { 0 };
	std::vector<std::string> scoreStrings;
};

