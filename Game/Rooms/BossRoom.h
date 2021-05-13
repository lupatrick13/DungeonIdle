#ifndef _BOSSROOM_
#define _BOSSROOM_
#pragma once
#include "Room.h"
#include "./LootTables/BossTable.h"

class BossRoom: public Room
{
private: 
	Equipment * dropped_item;
public:
	BossRoom(Player* parent) : Room(parent)
	{
		RoomMonster = new Mob( BOSS, "Daddy", BossTable(main->getLevel()), main->getLevel());
		dropped_item = nullptr;
	}
	virtual ~BossRoom() {}
	virtual play_state play(int choice = -1);
	virtual room_type get_type() { return room_type::BOSS_S; }
	virtual Equipment * getEquip();
	virtual Mob * getMob();
};

#endif
