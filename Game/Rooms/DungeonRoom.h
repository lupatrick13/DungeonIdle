#ifndef _DUNGEONROOM_
#define _DUNGEONROOM_
#pragma once
#include "Room.h"
#include "DungeonTable.h"
class DungeonRoom: public Room
{

public:
	DungeonRoom(Player* parent) : Room(parent)
	{
		Mob *RoomMonster = new Mob( REG, "Goblin", DungeonTable(main->getLevel()), main->getLevel());
	}
	virtual ~DungeonRoom() {}
	virtual play_state play(int choice = -1);
	virtual room_type get_type(){ return room_type::DUNGEON_S; }
	virtual map<string, string> get_drop();
	virtual Equipment * getLoot();
	virtual vector<string> get_Status(); 
	virtual Mob * getMob();
private:
	map<string, string> drop; // first string item name, second string description;
};

#endif
