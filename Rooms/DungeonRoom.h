#pragma once
#include "Room.h"

class DungeonRoom: public Room
{
private:
	int roomValue;
	int playerChoice;
	//MobEntity Minion;
public:
	DungeonRoom();
	void roomChoice(int rv, int pc);
	bool shopChance();
	void nextRoom();
};

