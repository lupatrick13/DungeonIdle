#ifndef _BOSSROOM_
#define _BOSSROOM_
#pragma once
#include "Room.h"
class BossRoom: public Room
{
private: 
	map<string, string> drop;
	Equipment * loot;
public:
	BossRoom(Player* parent) : Room(parent)
	{
		Mob *RoomMonster = new Mob( BOSS, "Daddy", BossTable(main->getLevel()), main->getLevel());
	}
	virtual ~BossRoom() {}
	virtual play_state play(int choice = -1);
	virtual room_type get_type() { return room_type::BOSS_S; }
	virtual map<string, string> get_drop();
	virtual Equipment * getLoot();
	virtual Mob * getMob();
};

#endif