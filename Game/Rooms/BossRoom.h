#pragma once

#include "Room.h"
class BossRoom: public Room
{
private: 
	map<string, string> drop;
	Equipment * loot;
public:
	BossRoom(Player* parent) : Room(parent) {
		RoomMonster= new Mob(MobType Boss, string name, LootComponent *drops, int level);
	}
	virtual ~BossRoom() {}
	virtual play_state play(int choice = -1);
	virtual room_type get_type() { return room_type::BOSS_S; }
	virtual map<string, string> get_drop();
	void generate_loot();
	Equipment * getLoot();
};

