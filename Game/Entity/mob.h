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
	int combatDMG() {
		int mobDMG, totalDMG = 0;
		mobDMG = (DMG * RANDOM_INT(1, 5));	
		if (mobType = BOSS) {
			mobDMG *= 2;
		}
		totalDMG = (mobDMG * (1 + (mobType / 100)));
		return totalDMG;
	}

	LootComponent *getLoot(){
		return droptable->roll();
	}
	
	//Equipment *combat(entity *opponent);

};



#endif /* MOB_H_ */
