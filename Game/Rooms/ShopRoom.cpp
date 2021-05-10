#include "ShopRoom.h"
#include "Room.h"
#include "EqpFactory.h"
#include "Equipment.h"
#include "ShopRoomTable.h"
#include <stdio.h>     
#include <stdlib.h>   
#include <time.h> 

play_state ShopRoom::play(int choice)
{
	bool enoughGold = checkGold(choice);
	if(!enoughGold){
		statusString = "Not enough gold";
	}
	if(choice == -1)
	{
		std::cout << "1. Heal " << heal.first << " : " << heal.second << "g"<< std::endl;
		std::cout << "2. Boost " << boost.first << " : " << boost.second << "g"<< std::endl;

		buyable["Heal"] = to_string(heal.first) + " life " + to_string(heal.second) + "g";
		buyable["Boost"] =to_string(boost.first) + " zooms " + to_string(boost.second) + "g";
		buyable["Equip"] =(ShopEquip->description()) + to_string(ShopEquip->get_value()) + "g";
		return play_state::OFFER;
	}
	else if(choice == 1 && enoughGold){
		main->setCurrentHP(main->getMaxHP() + heal.first);
		std::cout << "Bought heal" << std::endl;
		main->setGold(main->getGold() - heal.second);
		return play_state::DONE;

	}
	else if(choice == 2 && enoughGold){
		main->boostStats(boost.first);
		std::cout << "Bought boost" << std::endl;
		return play_state::DONE;
	}
	else if(choice == 3 && enoughGold){
			if(ShopEquip->get_base_stat().first == StatType::ARMOR){
				main->setArmor(ShopEquip);
				std::cout << "Bought Armor" << std::endl;
				return play_state::DONE;
			}else if(ShopEquip->get_base_stat().first == StatType::DMG){
				main->setWeapon(ShopEquip);
				std::cout << "Bought Weapon" << std::endl;
				return play_state::DONE;
		}
	}
	if(choice != -1)
		return play_state::DONE;
	return play_state::CONTINUE;
}

map<string, string> ShopRoom::get_drop()
{
	return buyable;
}

pair<int,int> ShopRoom::getHeal()
{
	return heal;
}

pair<int,int> ShopRoom::getBoost()
{
	return boost;
}

Equipment * ShopRoom::getEquip()
{
	return ShopEquip;
}
	
void ShopRoom::generateHeal()
{
	int amount = 3;
	int amount = (main->getMaxHP() * (1/RANDOM_INT(10,20)));
	int gold = (main->getLevel() * (1 + (1/RANDOM_INT(1,10))));

	heal = make_pair(amount, gold);
}
	
void ShopRoom::generateBoost()
{
	int amount = (main->getLevel() * (1/RANDOM_INT(10,20)));
	int gold = (main->getLevel() * (30 * (1/RANDOM_INT(1,20))));

	boost = make_pair(amount, gold);
}

void ShopRoom::generateEquip()
{
	ShopEquip = ShopTable(main->getLevel());
}

bool ShopRoom::checkGold(int choice)
{
	if(choice == 1){
		if(main->getGold() >= heal.second){
			return true;
		} else return false;
	}
	if(choice == 2){
		if(main->getGold() >= boost.second){
			return true;
		} else return false;
	}
	if(choice == 3){
		if(main->getGold() >= ShopEquip->get_value()){
			return true;
		} else return false;
	}
	return false;
}

