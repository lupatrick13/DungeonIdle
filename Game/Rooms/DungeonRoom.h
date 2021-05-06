#pragma once

#include "Room.h"

class DungeonRoom: public Room
{

public:
	DungeonRoom(Player* parent) : Room(parent){}
	virtual ~DungeonRoom() {}
	virtual play_state play(int choice = -1);
	virtual room_type get_type(){ return room_type::DUNGEON_S; }
	virtual map<string, string> get_loot();
	virtual string getloot();
	virtual vector<string> get_Status(); 
	virtual void generate_loot();
private:
	map<string, string> drop; // first string item name, second string description;
	Equipment * loot;
};


