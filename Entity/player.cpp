#include "player.h"
#include <iostream>

Player::Player() : Entity(level, name){
	exp = 0;
	level = 1;
	levelUp = 1;
	//bossRoomCounter = 0;
	set.first = nullptr;
	set.second = nullptr;
	gold = 0;

	HP.first = 20;
	HP.second = 20;
	stats[StatType::DMG] = 5;


}

void Player::setEXP(int e) {
	if (exp < levelUp) {
		exp = exp + e;
	}
	else if (exp >= levelUp) {
		exp = exp + e;
		levelUp = levelUp + 1;
	}
}

