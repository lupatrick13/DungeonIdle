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
	Equipment *combat(entity *opponent);

};



#endif /* MOB_H_ */
