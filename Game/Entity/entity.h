#ifndef ENTITY_H_
#define ENTITY_H_
#include "../Loot/LootComponent.h"
#include "../../util/RNG.h"
#include "../Equipment/Equipment.h"
#include <iostream>

using namespace std;

class Entity
{	
protected:
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
	Entity();
	virtual ~Entity() {}
	void getStats();
	virtual Equipment *combat(Entity *opponent) {return nullptr;};

};

#endif /* ENTITY_H_ */
