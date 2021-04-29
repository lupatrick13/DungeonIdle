/*
 * EqpFactory.h
 *
 *  Created on: Apr 25, 2021
 *      Author: patrick
 */

#ifndef EQUIPMENT_EQPFACTORY_H_
#define EQUIPMENT_EQPFACTORY_H_

#include "EqpDecoratorP.h"

class EquipmentFactory
{
public:
	EquipmentFactory(StatType type, Rarity rarity, std::string name, float value, float weight, int level): //type is only dmg or armor
		rarity(rarity), base_name(name), value(value), level(level), weight(weight), type(type) {}
	virtual ~EquipmentFactory() {}

	Equipment *make_eqp()
	{
		Equipment *Item = new Equipment(type, rarity, base_name, value, weight, level);
		Item = add_prefix(Item);
		return Item;
	}
	static Equipment *add_prefix(Equipment *item)
	{
		int size = sizeof(ALL_PREFIX)/ sizeof(ALL_PREFIX[0]);
		int choice = RANDOM_INT(0, ALL_PREFIX[size-1]);
		for(auto i : ALL_PREFIX)
		{
			if(choice < i)
			{
				switch(i)
				{
				case perfect:
					return new Perfect(item);
				case sharp:
					return new Sharp(item);
				default:
					return item;
				}
			}
		}
		return item;
	}

protected:
	StatType type;
	int level;
	Rarity rarity;
	std::string base_name;
	float weight, value;
};



#endif /* EQUIPMENT_EQPFACTORY_H_ */
