#ifndef ENTITY_H_
#define ENTITY_H_
#include "../Loot/LootComponent.h"
#include "../../util/RNG.h"
#include "../Equipment/Equipment.h"
#include <iostream>
#include <cmath>

using namespace std;

class Entity
{	
protected:
	std::map<int, int> stats;
	int SPEED;
	int DODGE;
	pair<float, float> HP; // first is currentHP, second is maxHP
	string name;
	int level;
	int exp;
	int gold;
public:
	Entity(int level, string name);
	virtual ~Entity() {}
	map<int, int> getStats();
	//virtual Equipment *combat(Entity *opponent) {return nullptr;};
	
	float getCurrentHP(){
		return HP.first;
	}
	
	float getMaxHP(){
		return HP.second;
	}
	
	float getSPEED(){
		return RANDOM_REAL(0.7, 1.3) *(SPEED + stats[StatType::AGI]);
	}

	float getDODGE(){
		return RANDOM_REAL(0.7, 1.3) *(DODGE + stats[StatType::DEX]);
	}

	void setCurrentHP(float i){
		HP.first = i;
	}

	virtual float combatDMG() = 0;
	
	string getName(){
		return name;
	}
	
	int getLevel(){
		return level;
	}

	int getEXP() {
		return exp;
	};
	int getGold(){
		return gold;
	}

	float getArmorReduc();

};




#endif /* ENTITY_H_ */
