#pragma once

#include "Room.h"

class DungeonRoom: public Room
{

public:
	DungeonRoom(Player* parent) : Room(parent) {}
	virtual ~DungeonRoom() {}
	virtual play_state play(int choice = -1);
	virtual room_type get_type(){ return room_type::DUNGEON_S; }
private:
	//MobEntity Minion;
};

