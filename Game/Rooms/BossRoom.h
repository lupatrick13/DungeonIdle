#pragma once

#include "Room.h"
class BossRoom: public Room
{
private: 
	//Entity Boss
public:
	BossRoom() {}
	virtual ~BossRoom() {}
	void resetSteps();
	virtual bool play(int choice = 0) {
		int RNG = RANDOM_INT(0, 20);
		std::cout << RNG << std::endl;
		return RNG < 1;  }
	virtual room_type get_type() { return room_type::BOSS_S; }
};

