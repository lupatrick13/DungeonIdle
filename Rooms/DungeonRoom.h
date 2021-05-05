#pragma once
#include "Room.h"
#include "entity.h"
#include "mob.h"
#include "player.h"

class DungeonRoom: public Room
{
private:
	//mob DungeonMob; 
	//std::vector<Room *>generate_room(int num_rooms);
	//MobEntity Minion;
public:
	DungeonRoom();
	virtual ~DungeonRoom();
	void roomChoice(int rv, int pc);
	virtual Room next_room(int playerChoice);
};

