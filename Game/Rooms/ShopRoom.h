#pragma once

#include "Room.h"
class ShopRoom: public Room
{
public:
	ShopRoom(Player* parent) : Room(parent) {};
	virtual ~ShopRoom() {}
	virtual room_type get_type(){ return room_type::SHOP_S; }
	virtual play_state play(int choice = -1);
private:
	pair<int, int> heal;
	pair<int, int> boost;
	pair<Equipment *, int> ShopEquip;
};

