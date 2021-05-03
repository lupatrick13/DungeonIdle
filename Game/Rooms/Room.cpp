#include "Room.h"

std::string GET_ROOM(room_type token)
{
	string name;
	switch(token)
	{
	case room_type::BOSS_S:
		name = "Boss";
		break;
	case room_type::SHOP_S:
		name = "Shop";
		break;
	case room_type::DUNGEON_S:
		name = "Dungeon";
		break;
	}
	return name;
}
