#include "BossRoom.h"
#include "BossTable.h"

play_state BossRoom::play(int choice)
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
		return play_state::DONE;
	}
	return play_state::CONTINUE;
}

map<string, string> BossRoom::get_loot()
{
	return drop;
}

void BossRoom::generate_loot()
{
	loot = BossTable(main->getLevel());
}