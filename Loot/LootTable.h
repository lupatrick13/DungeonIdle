/*
 * LootTable.h
 *
 *  Created on: Apr 24, 2021
 *      Author: patrick
 */

#ifndef LOOT_LOOTTABLE_H_
#define LOOT_LOOTTABLE_H_

#include "LootComponent.h"
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <random>

class LootTable : public LootComponent
{
public:
	LootTable(int weight, std::string name) : LootComponent(weight), droptable(name){}
	virtual ~LootTable() {}

	virtual LootComponent *roll()
	{
		std::cout << "Rolling table: " << droptable << std::endl;
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
		    std::random_device RNG;
		    std::mt19937 generator(RNG());
		    std::uniform_int_distribution<> distribution(0, num_range);
		    int choice = distribution(generator);
		    std::cout << "Choice : "<< choice << std::endl;
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
	virtual void print() { std::cout << droptable; }
	virtual void add(LootComponent *child) { children.push_back(child); }
private:
	std::string droptable;
	std::vector<LootComponent *> children;
};



#endif /* LOOT_LOOTTABLE_H_ */
