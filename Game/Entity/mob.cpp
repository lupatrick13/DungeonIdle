#include "mob.h"

Mob::Mob(MobType mobType, string name, LootComponent *drops, int level)
: Entity(level, name), mobType(mobType), droptable(drops)
{
	HP.first = 10;
	HP.second = 10;
	stats[StatType::DMG] = 5;

	int lower = 0;
	int upper = 5;
	if(mobType == BOSS){
		lower += 10;
		upper += 20;
	}
	for(int i=0; i<level; i++){	
		int randStat = RANDOM_INT(0,5);
		int randBoost = RANDOM_INT(lower, upper);
		stats[randStat] += randBoost;
		HP.first += randBoost;
		HP.second += randBoost;
		stats[StatType::DMG] += randBoost;
	}
}




/**

Equipment *mob::combat(entity *opponent) {
	
	if (mobType = REG) {
		int mobDMG = (DMG * RANDOM_INT(1, 5)) - (ARMOR * 0.5);
		int totalDMG = (mobDMG * (1 + (mobType / 100)));
		
	}
	else if (mobType = BOSS) {
		int mobDMG = (DMG * RANDOM_INT(1, 5)) - (ARMOR * 0.5);
	}
	int mobDMG = (DMG * RANDOM_INT(1,5)) - (ARMOR*0.5);
	//int hitChance = playerDodge * 
	int totalDMG = (mobDMG * (1 + (mobType/100);


	LootComponent *dropped = droptable->roll();
	return dropped->generate();
}

**/
