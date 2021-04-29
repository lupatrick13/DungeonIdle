#pragma once
#include "Room.h"

class DungeonRoom: public Room
{
private:
	int roomValue;
	int playerChoice;
	std::vector<Room *>generate_room(int num_rooms);
	//MobEntity Minion;
public:
	DungeonRoom();
	void roomChoice(int rv, int pc);
	bool shopChance();
	void nextRoom();
	virtual Room *go_next_room();
};

