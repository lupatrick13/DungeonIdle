#pragma once

#include "Room.h"
class BossRoom: public Room
{
private: 
	map<string, string> loot;
public:
	BossRoom(Player* parent) : Room(parent) {}
	virtual ~BossRoom() {}
	virtual play_state play(int choice = -1);
	virtual room_type get_type() { return room_type::BOSS_S; }
	virtual map<string, string> get_loot();
};

