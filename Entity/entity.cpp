#include "entity.h"
#include <iostream>


entity::entity() {
	HP = 100;
	ARMOR = 0;
	DMG = 0;
	SPEED = 0;
	DODGE = 0;
	STR = 0;
	MAGIC = 0;
	AGILITY = 0;
	DEX = 0;
}

void entity::getStats() {
	cout << HP, ARMOR, DMG, SPEED, DODGE, STR, MAGIC, AGILITY, DEX;

}


void entity::setStats() {
	HP = 100;
	ARMOR = 0;
	DMG = 0;
	SPEED = 0;
	DODGE = 0;
	STR = 0;
	MAGIC = 0;
	AGILITY = 0;
	DEX = 0;
}

void entity::combat() {

}
