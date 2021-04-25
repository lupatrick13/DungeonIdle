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
#include <random>

enum StatType : int
{
	DEX=2, STR=3, AGI=4, MAG=0,
	ARMOR = 1, DMG = 5
};
std::string GET_TYPE(int type)
{
	switch(type)
	{
	case ARMOR:
		return "ARMOR";
	case DEX:
		return "DEX";
	case STR:
		return "STR";
	case AGI:
		return "AGI";
	case MAG:
		return "MAG";
	case DMG:
		return "DMG";
	}
	return "DMG";
}
enum Rarity
{
	common = 0, rare = 2,
	epic = 5, legendary = 20
};

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

	    std::random_device RNG;
	    std::mt19937 generator(RNG());
	    std::uniform_int_distribution<> distributionS(0, 5);
	    std::uniform_int_distribution<> distributionV(0, 1 + level / 2);
	    std::uniform_real_distribution<> distributionR(0, 1.5);
		base_stat = std::make_pair(type, level * 100 * type * rarity * distributionR(RNG));

		for(int i =0; i<rarity; i++)
		{
			int type = distributionS(RNG);
			int amt = distributionV(RNG);
			if(type == DMG || type == ARMOR) amt *= 30;
			additional[type] += amt;
		}
	}
	virtual ~Equipment() {}

	virtual std::string description() { return get_rarity()+ " " + base_name; }
	virtual float get_weight() { return weight; }
	virtual float get_value() { return value; }
	virtual std::pair<int, float> get_base_stat() { return base_stat; }
	virtual std::map<int, float> get_additional() { return additional; }

	void print()
	{
		cout << description() + "!" << endl;
		cout << "Damage: " << base_stat.second << endl;
		cout << "Bonus stats!" << endl;
		map<int,float> additionals = get_additional();
		for(pair<int, float> add : additionals)
		{
			if(add.second)
			{
				cout << GET_TYPE(add.first) << ": " << add.second << " ";
			}
		}
	}

	std::string get_rarity()
	{
		switch(rarity)
		{
		case common:
			return "common";
		case rare:
			return "rare";
		case epic:
			return "epic";
		case legendary:
			return "legendary";
		}
		return "common";
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
