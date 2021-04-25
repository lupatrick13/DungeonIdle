#ifndef LOOT_H_
#define LOOT_H_

#include "LootComponent.h"

#include <iostream>
#include <string>

class Loot : public LootComponent {
public:
	Loot(int weight, std::string name) : LootComponent(weight), name(name) {}
	virtual ~Loot() {}

	virtual LootComponent *roll()
	{
		return this;
	}
	virtual void print()
	{
		std::cout << "Found ";

	}
	virtual void add(LootComponent *child) {}
private:
	std::string name;
};

#endif /* LOOT_H_ */
