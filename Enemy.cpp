#include <iostream>
#include <string>
#include "Enemy.h"

using namespace std;

//	Absolute value function
int absVal(int val)
{
    if (val < 0)
    {
        return -val;
    }
    return val;
}

Enemy::Enemy()
{
	name = "Unnamed";
	posX = 0;
	posY = 0;
    tarX = posX;
    tarY = posY;
    fresh = true;
    speed = 0;
}

Enemy::Enemy(string n, int x, int y)
{
	name = n;
	posX = x;
	posY = y;
	tarX = posX;
	tarY = posY;
    fresh = true;
    speed = 3;
}

Enemy::~Enemy()
{
    //cout << "Delete zombie at (" << posX << ", " << posY << ")" << endl;    
}


bool Enemy::collisionCheck(char dir, int i, char map[][10]) {
	int destX = posX;
	int destY = posY;

	//Find destination point
	if (dir == 'W') {
		destX -= i;
	}
	else if (dir == 'S') {
		destX += i;
	}
	else if (dir == 'A') {
		destY -= i;
	}
	else if (dir == 'D') {
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


int Enemy::move(int x, int y)
{
	tarX = x;
	tarY = y;
    int dist = absVal(tarX - posX) + absVal(tarY - posY);
    return dist;
}

int Enemy::getPosX()	{	return posX;	}

int Enemy::getPosY()	{	return posY;	}

void Enemy::setTarX(int tX)		{	tarX = tX;	}

void Enemy::setTarY(int tY)		{	tarY = tY;	}

string Enemy::getType()	{	return "Enemy";	}

void Enemy::print()
{
    cout << "Enemy: " << name << " at (" << posX << ", " << posY << ")" << endl;
}

void Enemy::move()
{
    int xDiff = tarX - posX;
    int yDiff = tarY - posY;

    // If player is within range, go stragiht to player
    if (absVal(xDiff) + absVal(yDiff) < speed)
    {
		cout << "Enemy: " << name << " approaches." << endl;
		posX = tarX + 1;
		posY = tarY;
        return;
    }

	//Traverse (alternating between x and y axis) towards player.
    int signX = 1;
    int signY = 1;
    if (xDiff < 0)
    {
        signX = -1;
    }
    if (yDiff < 0)
    {
        signY = -1;
    }


    for (int i = 0; i < speed; i++)
    {
        if ((i % 2 == 0) || (absVal(xDiff) > 0))
        {
			posX += signX;
        }
        else
        {
			posY += signY;
        }
    }
}