#pragma once
#include <string>
#include "GameCharacter.h"
#include "Weapon.h"

class Player : public GameCharacter
{
protected:
	char dir;
	int maxSpeed;
	int health;

	Weapon* weapon;

public:
	Player();
	Player(int x, int y);
	~Player();

	// Renamed move to be more accurate with the new
	// destination information
	void move(char dir, int space);
	int getMaxSpeed();
	int getPosX();
	int getPosY();
	void setPosX(int x);
	void setPosY(int y);
	void print();
	void setWeapon(weaponType type);
	string getType();

	bool collisionCheck(char dir, int space, char map[][10]);
};

