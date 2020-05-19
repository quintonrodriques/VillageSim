#include "Player.h"
#include <iostream>
#include <string>

using namespace std;


Player::Player()
{
	health = 10;
	posX = 0;
	posY = 0;
	dir = 'X';
	maxSpeed = 1;
	weapon = NULL;
}

Player::Player(int x, int y)
{
	health = 10;
	posX = x;
	posY = y;
	dir = 'W';
	maxSpeed = 3;
	weapon = NULL;
}

Player::~Player()
{
	const char* weaponName = "qtip";
	if (weapon != NULL)
	{
		weaponName = weapon->getWeaponName();
		//delete weapon;
	}
}


bool Player::collisionCheck(char dir, int i, char map[][10]) {
	int destX = posX;
	int destY = posY;

	//Find destination point
	if (dir == 'W') {
		destX -= i;
	}else if (dir == 'S') {
		destX += i;
	}else if(dir == 'A') {
		destY -= i;
	}else if(dir == 'D') {
		destY += i;
	}
	//If point falls outside of map bounds
	if (destX <= 0 || destX >= 10 || destY <= 0 || destY >= 10) {
		return false;
	}
	//Ensure point on the map is clear
	if (map[destX][destY] == ' ') {
		return true;
	}
	//Try another point
	return false;
}

void Player::move(char dir, int i) {
	if (dir == 'W') {
		posX -= i;
	}else if (dir == 'S') {
		posX += i;
	}else if (dir == 'A') {
		posY -= i;
	}else if (dir == 'D') {
		posY += i;
	}
	return;
}

void Player::setWeapon(weaponType type)
{
	if (weapon != NULL)
	{
		delete weapon;
	}
	weapon = new Weapon(type);
}

int Player::getPosX()		{	return posX;	}

int Player::getPosY()		{	return posY;	}

int Player::getMaxSpeed()	{	return maxSpeed;	}

void Player::setPosX(int x) {	posX = x;	}

void Player::setPosY(int y) {	posY = y;	}

string Player::getType()	{	return "Player";	}


void Player::print()
{
	cout << "Player is at (" << posX << ", " << posY << ")" << endl;
}
