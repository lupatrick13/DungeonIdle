#ifndef _DUNGEONROOM_
#define _DUNGEONROOM_
#pragma once
#include "Room.h"
#include "./LootTables/DungeonTable.h"
class DungeonRoom: public Room
{

public:
	DungeonRoom(Player* parent) : Room(parent)
	{
		RoomMonster = new Mob( REG, "Goblin",
			DungeonTable(main->getLevel()), main->getLevel());
		dropped_item = nullptr;
	}
	virtual ~DungeonRoom() {}
	virtual play_state play(int choice = -1);
	virtual room_type get_type(){ return room_type::DUNGEON_S; }
	virtual Equipment * getEquip();
	virtual Mob * getMob();
private:
	Equipment *dropped_item;
};

#endif
