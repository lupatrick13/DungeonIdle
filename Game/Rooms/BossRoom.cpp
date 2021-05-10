#include "BossRoom.h"
#include "BossTable.h"
#include "combat.h"

play_state BossRoom::play(int choice)
{
	
	if(choice == -1)
	{
		if (RoomMonster->getCurrentHP() != 0)
		{
			combat(main,RoomMonster);
			return play_state::CONTINUE;
		}
		else if(RoomMonster->getCurrentHP() == 0)
		{
			RoomMonster->getLoot()->generate();
			drop["loot"] = "Dropped a [item name]!";
			return play_state::LOOT;
		}
	}
	else if(choice != -1)
	{
		return play_state::DONE;
	}
	return play_state::CONTINUE;
}

map<string, string> BossRoom::get_drop()
{
	return drop;
}

Equipment * BossRoom::getLoot()
{
	return RoomMonster->getLoot()->generate();
}

Mob * BossRoom::getMob()
{
	return RoomMonster;
}
