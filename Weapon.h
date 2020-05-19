#pragma once
enum weaponType
{
    mace,
    flamethrower,
	qtip,
    punch
};

class Weapon
{
private:
    weaponType type;
    int force;
    int radius;

public:
    Weapon(weaponType type);
    ~Weapon();

    const char* getWeaponName();
    int getForce();
    int getRadius();
    weaponType getWeaponType();
};

