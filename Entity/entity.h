#ifndef ENTITY_H_
#define ENTITY_H_
#include "../Loot/LootComponent.h"
#include "../util/RNG.h"
#include "../Equipment/Equipment.h"
#include <iostream>

using namespace std;

class entity
{	
<<<<<<< Updated upstream:Entity/entity.h
private:
	int HP;
	int ARMOR;
	int DMG;
=======
protected:
	std::map<int, int> stats;
>>>>>>> Stashed changes:Game/Entity/entity.h
	int SPEED;
	int DODGE;
	pair<int, int> HP;

public:
<<<<<<< Updated upstream:Entity/entity.h
	entity();
	virtual ~entity() {}
	void getStats();
	virtual Equipment *combat(entity *opponent) {return nullptr;};
=======
	Entity();
	//virtual ~Entity() {}
	map<int, int> getStats();
	//virtual Equipment *combat(Entity *opponent) {return nullptr;};
	int getCurrentHP(){
		return HP.first;
	};
	int getMaxHP(){
		return HP.second;
	}
	int getSPEED(){
		return SPEED;
	};
	int getDODGE(){
		return DODGE;
	}
>>>>>>> Stashed changes:Game/Entity/entity.h

};




#endif /* ENTITY_H_ */
