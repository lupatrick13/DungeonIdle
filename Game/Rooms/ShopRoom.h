#pragma once

#include "Room.h"
class ShopRoom: public Room
{
public:
	ShopRoom(Player* parent) : Room(parent) {};
	virtual ~ShopRoom() {}
	virtual room_type get_type(){ return room_type::SHOP_S; }
	virtual play_state play(int choice = -1);
	virtual map<string, string> get_drop();
	pair<int,int> getHeal();
	pair<int,int> getBoost();
	virtual Equipment * getEquip();
	void generateHeal();
	void generateBoost();
	void generateEquip();
	bool checkGold(int choice);
	virtual vector<string> get_Status();
private:
	pair<int, int> heal;
	pair<int, int> boost;
	Equipment * ShopEquip;
	map<string, string> buyable;
};

