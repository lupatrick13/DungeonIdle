#include "DungeonRoom.h"
#include "Room.h"
#include <stdio.h>     
#include <stdlib.h>   
#include <time.h> 

play_state DungeonRoom::play(int choice)
{
	if(choice == -1)
	{
		int random = RANDOM_INT(0,3);
		if (random == 1)
		{
			return play_state::DONE;
		}
		else if(random == 2)
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
