#pragma once
class WindowResolution
{
public:
	WindowResolution();
	~WindowResolution();
	void setScreenWidth(unsigned int);
	void setScreenHeight(unsigned int);
	unsigned int getScreenWidth();
	unsigned int getScreenHeight();

private:
	unsigned int screenWidth;
	unsigned int screenHeight;
};

