#pragma once

#include "../Entity/AllEntity.h"
#include "../../util/RNG.h"

enum room_type
{
	SHOP_S=0, DUNGEON_S=1, BOSS_S=2
};

enum play_state
{
	OFFER, DONE, CONTINUE, LOOT
};
class Room
{
public:
	Room(Player* parent):main(parent), RoomMonster(nullptr)
	{}
	virtual ~Room() {}
	virtual play_state play(int choice = -1) { return play_state::CONTINUE; }
	virtual room_type get_type() { return room_type::DUNGEON_S; }

protected:
	Player *main;
	Mob *RoomMonster;
};

