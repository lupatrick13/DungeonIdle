/*
 * LootTable.h
 *
 *  Created on: Apr 24, 2021
 *      Author: patrick
 */

#ifndef LOOT_LOOTTABLE_H_
#define LOOT_LOOTTABLE_H_

#include "LootComponent.h"

class LootTable : public LootComponent
{
public:
	LootTable(int weight, std::string name) : LootComponent(weight), name(name){}
	virtual ~LootTable() {}

	virtual LootComponent *roll()
	{
		std::cout << "Rolling table: " << name << std::endl;
		int num_range = 0;
		std::map<int, int> DropRates;
		int index = 0;
		for(LootComponent *child: children)
		{
			num_range += child->get_weight();
			DropRates[index] = num_range;
			index++;
		}
		if(!num_range)
		{
			return nullptr;
		}
		else
		{
		    int choice = RANDOM_INT(0, num_range);
		    for(std::pair<int, int> item : DropRates)
		    {
		    	if(choice < item.second)
		    	{
		    		return children[item.first]->roll();
		    	}
		    }
		    return nullptr;
		}
	}
	virtual void print() { std::cout << name; }
	virtual void add(LootComponent *child) { children.push_back(child); }
	virtual Equipment *generate() {return nullptr; }
private:
	std::string name;
	std::vector<LootComponent *> children;
};



#endif /* LOOT_LOOTTABLE_H_ */
