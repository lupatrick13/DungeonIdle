#include "BossRoom.h"

play_state BossRoom::play(int choice)
{
	statusString->clear();
	statusString->resize(3);
	if(choice == -1)
	{
		if (RoomMonster->getCurrentHP() > 0)
		{
			combat(main,RoomMonster, statusString);
			return play_state::CONTINUE;
		}
		else if(RoomMonster->getCurrentHP() <= 0)
		{
			LootComponent *loottablecomp = RoomMonster->getLoot();
			if(loottablecomp == nullptr)
			{
				statusString->at(1) = "There's no drop unlucky!";
				return play_state::DONE;
			}
			else
			{
				dropped_item = loottablecomp->generate();
				statusString->at(1) = "Dropped a " + dropped_item->description()
					+ dropped_item->get_name();
				return play_state::LOOT;
			}
		}
	}
	else if(choice == 1)
	{
		statusString->at(1) = "Equipped " + dropped_item->description()
						+ dropped_item->get_name();
		bool wep = dropped_item->get_base_stat().first == StatType::DMG;
		if(wep)
			main->setWeapon(dropped_item);
		else
			main->setArmor(dropped_item);
		return play_state::DONE;
	}
	else if(choice == 2)
	{
		statusString->at(1) = "Left " + dropped_item->description()
								+ dropped_item->get_name();
		return play_state::DONE;
	}

	return play_state::CONTINUE;
}

Equipment * BossRoom::getEquip()
{
	return dropped_item;
}

Mob * BossRoom::getMob()
{
	return RoomMonster;
}
