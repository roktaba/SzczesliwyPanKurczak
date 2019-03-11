#include "GameMenu.h"



GameMenu::GameMenu()
{
	if (!menuFont.loadFromFile("fonts/JosefinSans-Regular.ttf"))
	{
		MessageBox(0, "Font not found!", "ERROR", 0);
		system("pause");
		return;
	}
}


GameMenu::~GameMenu()
{
}
