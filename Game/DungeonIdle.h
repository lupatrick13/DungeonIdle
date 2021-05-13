/*
 * DungeonIdle.h
 *
 *  Created on: Apr 30, 2021
 *      Author: patrick
 */

#ifndef GAME_DUNGEONIDLE_H_
#define GAME_DUNGEONIDLE_H_

#include "./Entity/AllEntity.h"
#include "../util/RNG.h"
#include "./Rooms/AllRooms.h"
#include <vector>

class DungeonIdle {
public:
	DungeonIdle();
	virtual ~DungeonIdle() {}
	play_state play(int choice = -1);

	void setRoomsCleared(int amt) { rooms_cleared = amt; }
	void setBosses_defeated(int amt) { bosses_defeated = amt; }
	void setBossCd(int amt) {boss_cd = amt; }
	void setShopChance(int amt) { shop_chance = amt; }

	int getRoomsCleared() { return rooms_cleared; }
	int getBosses_defeated() { return bosses_defeated;}
	int getBossCd() {return boss_cd; }
	int getShopChance() { return shop_chance; }
	Mob* getMob() { return curr_room->getMob();}
	room_type getRoomType(){ return roomtype; };
	std::vector<room_type> get_choice() {return choices;}
	Player *getPlayer() { return main; }
	Equipment *getEqp() { return curr_room->getEquip(); }

	void generate_choice();
	room_type generate_room(int choice);
	vector<string> *get_status() { return curr_room->get_Status(); }
private:
	Player *main;
	Room *curr_room;
	std::vector<room_type> choices;
	int rooms_cleared, bosses_defeated,
		boss_cd, shop_chance;
	room_type roomtype;
};

#endif /* GAME_DUNGEONIDLE_H_ */
