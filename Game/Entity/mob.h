#ifndef MOB_H_
#define MOB_H_

#include "entity.h"

using namespace std;

class Mob: public Entity
{
private:
	MobType mobType;
	LootComponent *droptable;

public:
	Mob(MobType mobType, string name, LootComponent *drops, int level);
	virtual ~Mob() {}
	MobType getMobType() { return mobType; }
	float combatDMG() {
		float mobDMG, totalDMG = 0;
		mobDMG = (stats[DMG] * RANDOM_REAL(0.8, 2.2));
		if (mobType == BOSS) {
			mobDMG *= 3;
		}
		totalDMG = (mobDMG * (1 + (mobType / 20)));
		return totalDMG;
	}

	LootComponent *getLoot(){
		return droptable->roll();
	}
	
	//Equipment *combat(entity *opponent);

};



#endif /* MOB_H_ */
