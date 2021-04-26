/*
 * LootComponent.h
 *
 *  Created on: Apr 24, 2021
 *      Author: patrick
 */

#ifndef LOOT_LOOTCOMPONENT_H_
#define LOOT_LOOTCOMPONENT_H_
#include "../Equipment/EqpFactory.h"

class LootComponent {
public:
	LootComponent(int weight) : weight(weight) {}
	virtual ~LootComponent() {};

	virtual LootComponent *roll() = 0;
	virtual void add(LootComponent *child) = 0;
	virtual void print() = 0;
	virtual Equipment *generate() = 0;
	int get_weight() { return weight; }

protected:
	int weight;
};

#endif /* LOOT_LOOTCOMPONENT_H_ */
