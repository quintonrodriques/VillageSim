#include <iostream>
#include "Weapon.h"

using namespace std;
//Unimplemented atm

Weapon::Weapon(weaponType type)
{
    this->type = type;
    switch (type)
    {
    case mace:
        force = 4;
        radius = 2;
        break;
    case flamethrower:
        force = 2;
        radius = 4;
        break;
    case qtip:
        force = 1;
        radius = 1;
        break;
    default:
        force = 2;
        radius = 3;
    }
}

Weapon::~Weapon()
{
    cout << "Weapon " << type << " destroyed" << endl;
}

const char* Weapon::getWeaponName()
{
    switch (type)
    {
    case mace:
        return "mace";
    case flamethrower:
        return "flamethrower";
    case qtip:
        return "q-tip";
    default:
        return "punch";
    }
}

int Weapon::getForce()
{
    return force;
}

int Weapon::getRadius()
{
    return radius;
}

weaponType Weapon::getWeaponType()
{
    return type;
}