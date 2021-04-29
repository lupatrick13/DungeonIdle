#include "mob.h"

mob::mob(MobType mobType, string name, LootComponent *drops)
: entity(), mobType(mobType), mobName(name), droptable(drops)
{

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
