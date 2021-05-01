#pragma once

#include "Room.h"
class ShopRoom: public Room
{
public:
	ShopRoom();
	virtual ~ShopRoom() {}
	virtual room_type get_type(){ return room_type::SHOP_S; }
	virtual bool play(int choice = 0) { return choice > 2; }
private:
	pair<int, int> heal;
	pair<int, int> boost;
	pair<Equipment *, int> ShopEquip;
};

