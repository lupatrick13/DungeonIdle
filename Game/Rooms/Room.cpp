/*
 * Room.cpp
 *
 *  Created on: May 10, 2021
 *      Author: patrick
 */

#include "Room.h"

std::string GET_ROOM(room_type roomtype)
{
	switch(roomtype)
	{
	case SHOP_S:
		return "SHOP";
	case DUNGEON_S:
		return "DUNGEON";
	case BOSS_S:
		return "BOSS";
	}
	return "DUNGEON";
}


