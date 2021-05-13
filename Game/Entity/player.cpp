#include "player.h"
#include <iostream>

Player::Player() : Entity(1, "Group 4"){
	exp = 0;
	levelUp = 10;
	set.first = nullptr;
	set.second = nullptr;
	gold = 0;

	HP.first = 20;
	HP.second = 20;
	stats[StatType::DMG] = 7;


}

void Player::level_up()
{
	if(exp >= levelUp)
	{
		int exp_prev = exp;
		exp_prev -= levelUp;
		level++;
		stats[StatType::MAG] += RANDOM_INT(0,3);
		stats[StatType::ARMOR] += RANDOM_INT(0,3);
		stats[StatType::DEX] += RANDOM_INT(0,3);
		stats[StatType::STR] += RANDOM_INT(0,3);
		stats[StatType::AGI] += RANDOM_INT(0,3);
		stats[StatType::DMG] += RANDOM_INT(0,3);
		HP.first += RANDOM_INT(0,80);
		HP.second += RANDOM_INT(0,80);
		levelUp = pow(2.123, level /2 + 1) + level * 10;

		exp = 0;
		if(exp_prev > 0)
			setEXP(exp_prev);
	}
}

void Player::setEXP(float e) {
	float temp = exp;
	temp += e;

	exp += floor(temp);
	level_up();
}

