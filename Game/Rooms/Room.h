#pragma once

#include "../Entity/AllEntity.h"
#include "../../util/RNG.h"

enum room_type
{
	SHOP_S=0, DUNGEON_S=1, BOSS_S=2
};
class Room
{
public:
	Room(): RoomMonster(nullptr)
	{}
	virtual ~Room() {}
	virtual bool play(int choice = 0) { return false; }
	virtual room_type get_type() { return room_type::DUNGEON_S; }

protected:
	Mob *RoomMonster;
};

