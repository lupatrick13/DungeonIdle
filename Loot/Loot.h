#ifndef LOOT_H_
#define LOOT_H_

#include "LootComponent.h"

class Loot : public LootComponent {
public:
	Loot(int weight, EquipmentFactory *eqp) : LootComponent(weight), eqp(eqp) {}
	virtual ~Loot() {}

	virtual LootComponent *roll()
	{
		return this;
	}
	virtual void print()
	{
		std::cout << "Found ";

	}
	virtual Equipment *generate()
	{
		return eqp->make_eqp();
	}
	virtual void add(LootComponent *child) {}
private:
	EquipmentFactory *eqp;
};

#endif /* LOOT_H_ */
