#include "DeltaTime.h"



DeltaTime::DeltaTime()
{
	deltaTime.restart();
	dt = deltaTime.getElapsedTime().asSeconds();
}


DeltaTime::~DeltaTime()
{
}

double DeltaTime::getDT()
{
	dt = deltaTime.getElapsedTime().asSeconds();
	return dt;
}

void DeltaTime::restartDT()
{
	deltaTime.restart();
}
