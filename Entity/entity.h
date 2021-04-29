#ifndef ENTITY_H_
#define ENTITY_H_
#include "../Loot/LootComponent.h"

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
	void setStats();
	virtual Equipment *combat(entity *opponent) {return nullptr;};

};

#endif /* ENTITY_H_ */
