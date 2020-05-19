#pragma once
#include <string>
#include "GameCharacter.h"
#include "Weapon.h"

class Enemy : public GameCharacter
{
protected:
    int tarX;
    int tarY;
    bool fresh;
	std::string name;

public:
	Enemy();
	Enemy(std::string n, int x, int y);
    ~Enemy();

    int move(int x, int y);
	int getPosX();
	int getPosY();
	string getType();
	void setTarX(int tX);
	void setTarY(int tY);

    void print();

    void move();
	bool collisionCheck(char dir, int space, char map[][10]);
};

