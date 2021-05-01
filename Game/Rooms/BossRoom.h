#pragma once

#include "Room.h"
class BossRoom: public Room
{
private: 
	//Entity Boss
public:
	BossRoom(Player* parent) : Room(parent) {}
	virtual ~BossRoom() {}
	virtual play_state play(int choice = -1);
	virtual room_type get_type() { return room_type::BOSS_S; }
};

