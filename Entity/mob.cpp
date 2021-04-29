#include "mob.h"
#include <iostream>

void mob::getStats() {
	entity::getStats;
}

void mob::setStats() {
	entity::setStats;
}

void mob::randomLoot() {

}

void mob::getLoot() {

}

string mob::getMobName() {

}

string mob::getMobType(){
	
}

void mob::combat() {
	/**
	* mobDMG = (playerLevel * RNG(1-5)) - (playerArmor*0.5);
	* hitChance = playerDodge * 
	totalDMG = (mobDMG * (1 + (mobType/100);
	*/
}