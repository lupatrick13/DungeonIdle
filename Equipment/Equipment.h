/*
 * Equipment.h
 *
 *  Created on: Apr 24, 2021
 *      Author: patrick
 */

#ifndef EQUIPMENT_EQUIPMENT_H_
#define EQUIPMENT_EQUIPMENT_H_

#include <vector>
#include <map>
#include <iostream>
#include "../util/RNG.h"
#include "../util/EnumConverters.h"

using namespace std;

class Equipment
{
public:
	Equipment (const Equipment & RHS)
	{
		level = RHS.level;
		rarity = RHS.rarity;
		base_name = RHS.base_name;
		weight = RHS.weight;
		value = RHS.value;
		additional = RHS.additional;
		base_stat = RHS.base_stat;
	}

	Equipment(StatType type, Rarity rarity, std::string name, float value, float weight, int level): //type is only dmg or armor
		rarity(rarity), base_name(name), value(value), level(level), weight(weight)
	{
		base_stat = std::make_pair(type, level * 10 * type * rarity * RANDOM_REAL(0,1.5));

		for(int i =0; i<rarity; i++)
		{
			int type = RANDOM_INT(0,5);
			int amt = RANDOM_REAL(0, 1 + (float)level / 2);
			if(type == DMG || type == ARMOR) amt *= 30;
			additional[type] += amt;
		}
	}
	virtual ~Equipment() {}

	virtual std::string description() { return GET_RARITY(rarity)+ " " + base_name; }
	virtual float get_weight() { return weight; }
	virtual float get_value() { return value; }
	virtual std::pair<int, float> get_base_stat() { return base_stat; }
	virtual std::map<int, float> get_additional() { return additional; }

	void print()
	{
		cout << description() + "!" << endl;
		cout << GET_TYPE(base_stat.first) << ": " << base_stat.second << endl;

		map<int,float> additionals = get_additional();
		if(additionals.size())
			cout << "Bonus stats!" << endl;
		for(pair<int, float> add : additionals)
		{
			if(add.second)
			{
				cout << GET_TYPE(add.first) << ": " << add.second << " ";
			}
		}
	}

protected:
	int level;
	Rarity rarity;
	std::string base_name;
	float weight, value;
	std::map<int, float> additional;
	std::pair<int, float> base_stat;
};


#endif /* EQUIPMENT_EQUIPMENT_H_ */
