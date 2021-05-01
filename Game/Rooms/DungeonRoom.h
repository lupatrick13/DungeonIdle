#pragma once

#include "Room.h"

class DungeonRoom: public Room
{

public:
	DungeonRoom();
	virtual ~DungeonRoom() {}
	virtual bool play(int choice = 0) {
		return RANDOM_INT(0, 2) < 1; }
	virtual room_type get_type(){ return room_type::DUNGEON_S; }
private:
	//MobEntity Minion;
};

