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
	pair<int, int> HP; // first is currentHP, second is maxHP
	string name;
	int level;

public:
	Entity(int level, string name);
	virtual ~Entity() {}
	map<int, int> getStats();
	//virtual Equipment *combat(Entity *opponent) {return nullptr;};
	int getCurrentHP(){
		return HP.first;
	};
	int getMaxHP(){
		return HP.second;
	}
	int getSPEED(){
		return SPEED + stats[StatType::AGI];
	};
	int getDODGE(){
		return DODGE + stats[StatType::DEX];
	}
	void setCurrentHP(int i){
		HP.first = i;
	}
	virtual int getCombatDMG() = 0;
	string getName(){
		return name;
	}
	int getLevel(){
		return level;
	}


};




#endif /* ENTITY_H_ */
