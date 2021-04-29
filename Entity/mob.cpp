#include "mob.h"

mob::mob(MobType mobType, string name, LootComponent *drops)
: entity(), mobType(mobType), mobName(name), droptable(drops)
{

}
Equipment *mob::combat(entity *opponent) {
	/**
	* mobDMG = (playerLevel * RNG(1-5)) - (playerArmor*0.5);
	* hitChance = playerDodge * 
	totalDMG = (mobDMG * (1 + (mobType/100);
	*/

	LootComponent *dropped = droptable->roll();
	return dropped->generate();
}
