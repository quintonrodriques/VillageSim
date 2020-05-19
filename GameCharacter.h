#pragma once
//#ifndef GAMECHARACTER_H
//#define GAMECHARACTER_H
#include <string>

using namespace std;

class GameCharacter
{
public:
	int posX;
	int posY;
	int speed;
	int health;

	GameCharacter();
	GameCharacter(string n, int x, int y);
	~GameCharacter();

	int getPosX();
	int getPosY();
	virtual string getType() = 0;

	void print();
};

