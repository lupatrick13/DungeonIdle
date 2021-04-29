#ifndef ENTITY_H_
#define ENTITY_H_
#include "../Loot/LootComponent.h"
#include "../util/RNG.h"
#include "../Equipment/Equipment.h"
#include <iostream>

using namespace std;

class entity
{	
private:
	int HP;
	int ARMOR;
	int DMG;
	int SPEED;
	int DODGE;
	int STR;
	int MAGIC;
	int AGILITY;
	int DEX;

public:
	entity();
	virtual ~entity() {}
	void getStats();
	virtual Equipment *combat(entity *opponent) {return nullptr;};

};

#endif /* ENTITY_H_ */
