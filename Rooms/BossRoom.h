#pragma once

#include "Room.h"
class BossRoom: public Room
{
private: 
	//Entity Boss
public:
	void resetSteps();
	void bossCount();
	virtual Room *go_next_room() { return nullptr; }
};

