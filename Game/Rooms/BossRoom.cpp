#include "BossRoom.h"


play_state BossRoom::play(int choice)
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
			loot["loot"] = "Dropped a [item name]!";
			return play_state::LOOT;
		}
	}
	else if(choice != -1)
	{
		return play_state::DONE;
	}
	return play_state::CONTINUE;
}

map<string, string> BossRoom::get_loot()
{
	return loot;
}
