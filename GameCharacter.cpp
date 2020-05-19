#include "GameCharacter.h"
#include <iostream>
#include <string>


GameCharacter::GameCharacter()
{
	posX = 0;
	posY = 0;
	speed = 0;
	health = 1;
}

GameCharacter::~GameCharacter()
{
	
}

int GameCharacter::getPosX()
{
	return posX;
}

int GameCharacter::getPosY()
{
	return posY;
}

void GameCharacter::print()
{
	cout << "Game Character at (" << posX << ", " << posY << ")" << endl;
}

