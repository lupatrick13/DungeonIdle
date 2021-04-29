#include "player.h"
#include <iostream>

player::player() {
	exp = 0;
	level = 0;
	levelUp = 0;
	statPoints = 0;
	bossRoomCounter = 0;
	entity();

}

void player::getStats() {
	entity::getStats; 
}

void player::setStats() {
	entity::setStats;
}

void player::getEXP() {
	
}

void player::setEXP(int e) {
	if (exp < levelUp) {
		exp = exp + e;
	}
	else if (exp >= levelUp) {
		exp = exp + e;
		statPoints = statPoints + 10;
		levelUp = levelUp + 1;
	}
}

int player::getLevel() {
	return level;
}

void player::setLevel() {

}

void player::combat() {
	/**
	* if(
	totalDMG = (weaponDMG * (1 + (weaponStat/100))) + (playerDMG * (1 + (playerStat/100)));
	*/
}