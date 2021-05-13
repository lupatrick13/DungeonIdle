#include "mob.h"

Mob::Mob(MobType mobType, string name, LootComponent *drops, int level)
: Entity(level, name), mobType(mobType), droptable(drops)
{
	HP.first = RANDOM_INT(5*level, 50*level);
	HP.second = HP.first;
	stats[StatType::DMG] = RANDOM_REAL(level * 3, level * 7);

	int lower = RANDOM_INT(0, level/3);
	int upper = RANDOM_INT(level, level*2);
	if(mobType == BOSS){
		lower *= 3;
		upper *= 6;
	}
	for(int i=0; i<level/2 +1; i++){
		int randStat = RANDOM_INT(0,5);
		int randBoost = RANDOM_INT(lower, upper);
		stats[randStat] += randBoost;
		HP.first += randBoost;
		HP.second += randBoost;
		stats[StatType::DMG] += randBoost / 3;
	}

	float tempe = 0;
	float tempg = 0;
	for(int i = 0; i < 6; i++)
	{
		tempg += stats[i] *RANDOM_REAL(0.5, 1.2) * level / 2;

		tempe += stats[i] *RANDOM_REAL(0.7, 1.4) * level;
	}
	exp = tempe;
	gold = tempg;
}


