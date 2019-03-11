#include "WindowResolution.h"



WindowResolution::WindowResolution()
{
	screenWidth = 1024;
	screenHeight = 768;
}


WindowResolution::~WindowResolution()
{
}

void WindowResolution::setScreenWidth(unsigned int x)
{
	screenWidth = x;
}

void WindowResolution::setScreenHeight(unsigned int x)
{
	screenHeight = x;
}

unsigned int WindowResolution::getScreenWidth()
{
	return screenWidth;
}

unsigned int WindowResolution::getScreenHeight()
{
	return screenHeight;
}
