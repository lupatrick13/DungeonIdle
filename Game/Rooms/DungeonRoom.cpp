#include "DungeonRoom.h"
#include "Room.h"
#include "DungeonTable.h"
#include <stdio.h>     
#include <stdlib.h>   
#include <time.h> 

play_state DungeonRoom::play(int choice)
{
	RoomMonster->generate_Mob();
	if(choice == -1)
	{
		if (!mobdead)
		{
			main->attack(DungeonMob);
			return play_state::CONTINUE;
		}
		else if(mobddead)
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

map<string, string> DungeonRoom::get_loot()
{
	return drop;
}

string DungeonRoom::getloot()
{
	return loot->description();
}

void DungeonRoom::generate_loot()
{
	loot = DungeonTable(main->getLevel());
}