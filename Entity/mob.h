#ifndef MOB_H_
#define MOB_H_

#include "entity.h"

using namespace std;

class mob: public entity
{
private:
	MobType mobType;
	string mobName;
	LootComponent *droptable;

public:
	mob(MobType mobType, string name, LootComponent *drops);
	virtual ~mob() {}
	MobType getMobType() { return mobType; }
	string getMobName() { return mobName; }
	int combatDMG() {
		int mobDMG, totalDMG = 0;
		if (mobType = REG) {
			mobDMG = (DMG * RANDOM_INT(1, 5)) - (ARMOR * 0.5);
			totalDMG = (mobDMG * (1 + (mobType / 100)));

		}
		else if (mobType = BOSS) {
			mobDMG = (DMG * RANDOM_INT(1, 5) * 2) - (ARMOR * 0.5);
			totalDMG = (mobDMG * (1 + (mobType / 100)));
		}
		return totalDMG;
	}

	//Equipment *combat(entity *opponent);

};



#endif /* MOB_H_ */
