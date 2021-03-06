/*
 * RoomFactory.h
 *
 *  Created on: Apr 30, 2021
 *      Author: patrick
 */

#ifndef GAME_ROOMS_ROOMFACTORY_H_
#define GAME_ROOMS_ROOMFACTORY_H_

#include "BossRoom.h"
#include "DungeonRoom.h"
#include "ShopRoom.h"


class RoomFactory
{
public:
	RoomFactory();
	virtual ~RoomFactory(){}

	static Room* make_room(room_type which, Player *parent)
	{
		switch(which)
		{
		case room_type::SHOP_S:
			return new ShopRoom(parent);
		case room_type::DUNGEON_S:
			return new DungeonRoom(parent);
		case room_type::BOSS_S:
			return new BossRoom(parent);
		}
		return nullptr;
	}
};



#endif /* GAME_ROOMS_ROOMFACTORY_H_ */
