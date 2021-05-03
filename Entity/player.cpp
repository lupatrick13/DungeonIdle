#include "player.h"
#include <iostream>

player::player() {
	exp = 0;
	level = 0;
	levelUp = 0;
	statPoints = 0;
	bossRoomCounter = 0;

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

int player::getSteps(){
	return stepsTilNextBoss;
}

void player::setSteps(int steps){
	stepsTilNextBoss = steps;
}

int player::getBossRoomCounter(){
	return bossRoomCounter;
}