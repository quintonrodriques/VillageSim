#include <iostream>
#include <string>
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include <memory>

using namespace std;

const int MAP_SIZE = 10;

vector<GameCharacter*> mobs;

//Outputs map visualzation to console
void printMap(char m[][MAP_SIZE]) {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			cout << m[i][j];
			if (j == MAP_SIZE - 1) {
				cout << endl;
			}
		}
	}
}

//Assigns cells a character, X is wall, E is enemy, _ is free space 
void updateMap(char m[][MAP_SIZE]) {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			//Draw border along map edge
			if (i == 0 || i == std::size(m[i]) - 1 || j == 0 || j == std::size(m[j]) - 1) {
				m[i][j] = 'X';
			}
			else {
				m[i][j] = ' ';
			}
			//Label all characters, player + npcs
			for (auto mo : mobs) {
				if (mo->getPosX() == i && mo->getPosY() == j) {
					if (mo->getType() == "Enemy") {
						m[i][j] = 'E';
					}else if (mo->getType() == "Player") {
						m[i][j] = 'P';
					}
				}
			}
			//Presumed empty
			if(m[i][j] != 'X' && m[i][j] != 'E' && m[i][j] != 'P'){
				m[i][j] = ' ';
			}
		}
	}
}

//Ensure player input was a given direction
char directionCheck(char d) {
	if (d == 'W' || d == 'w') {
		return 'W';
	}
	if (d == 'A' || d == 'a') {
		return 'A';
	}
	if (d == 'S' || d == 's') {
		return 'S';
	}
	if (d == 'D' || d == 'd') {
		return 'D';
	}
	//Invalid response
	return 'X';
}

//Ensure player input was a signle digit number
int movementCheck(char d) {
	if (d == '0' || d == '1'|| d == '2' || d == '3' || d == '4' || d == '5' || d == '6' || d == '7' || d == '8' || d == '9') {
		return d - '0';
	}
	//Invalid response
	return -1;
}

int main()
{
	
	Enemy e1("Fred", 4, 4);
	Enemy e2("Princeton", 3, 3);
	Player p1(7, 3);

	mobs.clear();

	mobs.push_back(&e1);
	mobs.push_back(&e2);
	mobs.push_back(&p1);

	char map[MAP_SIZE][MAP_SIZE];


	updateMap(map);
	printMap(map);

	
	for (int i = 0; i < 15; i++) {
		bool errorCheck = false;
		char input = 'X';

		char direction = 'X';
		int spaces = 0;

		cout << "Enter the direction you want to move towards. [W] [A] [S] [D]" << endl;
		while(errorCheck == false){
			cin >> input;
			//If invalid option given
			if (directionCheck(input) == 'X') {
				cout << "Invalid option! Enter the direction you want to move towards. [W] [A] [S] [D]" << endl;
			}
			else {
				errorCheck = true;
				direction = directionCheck(input);
			}
		}

		errorCheck = false;
		cout << "Enter the number of spaces you would like to travel. Min: [0] Max: [" << p1.getMaxSpeed() << "]" << endl;
		while (errorCheck == false) {
			cin >> input;
			if (movementCheck(input) == -1 || movementCheck(input) > p1.getMaxSpeed()) {
				cout << "Invalid option! Enter the number of spaces you would like to travel. Min: [0] Max: [" << p1.getMaxSpeed() << "]" << endl;
			}
			else {

				spaces = movementCheck(input);
				if (spaces == 0) {
					cout << "Player turned on the spot!" << endl;
					errorCheck = true;
					p1.move(direction, spaces);
				}
				else {

					if (p1.collisionCheck(direction, spaces, map)) {
						errorCheck = true;
						p1.move(direction, spaces);
					}
					else {
						cout << "Invalid option! Check you are not moving onto an occupied space. Enter the number of spaces you would like to travel. Min: [0] Max: [" << p1.getMaxSpeed() << "]" << endl;
					}
				}
			}
		}

		//Update players position to enemies and move them
		for (auto mo : mobs) {
			if (mo->getType() == "Enemy") {
				Enemy* c = dynamic_cast<Enemy*>(mo);
				c->setTarX(p1.getPosX());
				c->setTarY(p1.getPosY()
				);
				c->move();
			}
		}

		//Add dividing section
		for (int j = 0; j <= 10; j++) {
			cout << endl;
		}

		//Update and render map
		updateMap(map);
		printMap(map);
	}
}

