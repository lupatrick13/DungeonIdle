/*
 * TesGame.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: patrick
 */

#include "../Game/DungeonIdle.h"
#include <string>
using namespace std;
void TesGame()
{
	DungeonIdle *game = new DungeonIdle();
	while (1)
	{
		game->generate_choice();

		std::vector<room_type> choices = game->get_choice();
		int index = 0;
		for(room_type token: choices)
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
			cout << "Choice " << index << ": " << name << endl;
			index++;
		}

		int choice;
		cin >> choice;
		game->generate_room(choice);

		while(!game->play())
		{
			cout<< "THIS MANY TIMES" << endl;
		}
		cout << game->getBossCd() << " many steps til boss" << endl;
	}

}

