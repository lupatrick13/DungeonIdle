/*
 * DungeonIdle.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: patrick
 */

#include "DungeonIdle.h"

DungeonIdle::DungeonIdle()
{
	shop_chance = 25;
	rooms_cleared = 0;
	boss_cd = 10;
	bosses_defeated = 0;
	main = new Player();
	curr_room = nullptr;
}

void DungeonIdle::generate_choice()
{
	choices.clear();
	if(boss_cd)
	{
		for (int i = 0; i < 3; i++)
		{
			bool shop = RANDOM_INT(0,100) < shop_chance;
			if(shop)
				choices.push_back(room_type::SHOP_S);
			else
				choices.push_back(room_type::DUNGEON_S);
		}
		boss_cd--;
	}
	else
	{
		choices.push_back(room_type::BOSS_S);
		boss_cd = 10;
	}
	shop_chance = RANDOM_INT(1,24);
}

room_type DungeonIdle::generate_room(int choice)
{
	curr_room = RoomFactory::make_room(choices[choice], main);
	return choices[choice];
}

play_state DungeonIdle::play(int choice)
{
	play_state status = curr_room->play(choice);

	room_type type = curr_room->get_type();
	if(type != room_type::SHOP_S && status == play_state::DONE)
	{
		if(type == room_type::BOSS_S)
			bosses_defeated += 1;
		rooms_cleared += 1;
	}
	return status;
}
