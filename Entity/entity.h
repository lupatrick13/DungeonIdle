#ifndef ENTITY_H_
#define ENTITY_H_
#include "../Loot/LootComponent.h"
#include "../util/RNG.h"
#include "../Equipment/Equipment.h"
#include <iostream>

using namespace std;

class Entity
{	
protected:
	std::map<int, int> stats;
	int SPEED;
	int DODGE;
	pair<int, int> HP;

public:
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

};




#endif /* ENTITY_H_ */
