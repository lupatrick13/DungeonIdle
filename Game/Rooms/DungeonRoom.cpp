#include "DungeonRoom.h"
#include "Room.h"
#include "DungeonTable.h"
#include <stdio.h>     
#include <stdlib.h>   
#include <time.h> 

play_state DungeonRoom::play(int choice)
{
	if(choice == -1)
	{
		if (RoomMonster->getCurrentHP() != 0)
		{
			main->attack(DungeonMob);
			return play_state::CONTINUE;
		}
		else if(RoomMonster->getCurrentHP() == 0)
		{
			drop["loot"] = "Dropped a [item name]!";
			return play_state::LOOT;
		}
	}
	else if(choice != -1)
	{
		std::cout << "Got loot! from choice: " << choice << std::endl;
		return play_state::DONE;
	}
	return play_state::CONTINUE;
}

map<string, string> DungeonRoom::get_drop()
{
	return drop;
}

Equipment * DungeonRoom::getLoot()
{
	return loot;
}

void DungeonRoom::generate_loot()
{
	loot = DungeonTable(main->getLevel());
}