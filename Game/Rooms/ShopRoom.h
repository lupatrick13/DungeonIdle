#ifndef _SHOPROOM_
#define _SHOPROOM_
#pragma once
#include "Room.h"
#include "./LootTables/ShopRoomTable.h"

class ShopRoom: public Room
{
public:
	ShopRoom(Player* parent) : Room(parent) {
		generateHeal();
		generateBoost();
		generateEquip();
	};
	virtual ~ShopRoom() {}
	virtual room_type get_type(){ return room_type::SHOP_S; }
	virtual play_state play(int choice = -1);
	pair<int,int> getHeal();
	pair<int,int> getBoost();
	virtual Equipment * getEquip();
	Mob *getMob() { return nullptr; }
private:
	void generateHeal();
	void generateBoost();
	void generateEquip();
	bool checkGold(int choice);
	pair<int, int> heal;
	pair<int, int> boost;
	Equipment * ShopEquip;
};

#endif
