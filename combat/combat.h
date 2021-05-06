#ifndef COMBAT_H_
#define COMBAT_H_

#include "../Entity/entity.h"
#include "../Entity/player.h"
#include "../Entity/mob.h"

using namespace std;

pair<int, bool> combat(Player a, mob b){
	bool dead = false;
	int i = 0;

	int nowPlayerHP = a.getCurrentHP();
	int maxPlayerHP = a.getMaxHP() ;
	int playerDMG = a.combatDMG();
	
	int dodgeChance = a.getDODGE();
	bool dodge = false; 
	if(dodgeChance * RANDOM_INT(1,5) > 100){
		dodge = true;
	} 
	int atk2Chance = a.getSPEED();
	bool atk2 = false;
	if(atk2Chance * RANDOM_INT(1,5) > 100){
		atk2 = true;
	}

	int mobHP = b.getCurrentHP();
	int mobDMG = b.combatDMG();

	if(nowPlayerHP > 0 && mobHP > 0 && dodge && atk2){
		//nowPlayerHP = nowPlayerHP - mobDMG;
		//mobHP = mobHP - 2 * playerDMG;
		mobHP = mobHP -  playerDMG;
		combat(a, b);
	}
	else if(nowPlayerHP > 0 && mobHP > 0 && !dodge && atk2){
		nowPlayerHP = nowPlayerHP - mobDMG;
		//mobHP = mobHP - 2 * playerDMG;
		mobHP = mobHP - playerDMG;
		combat(a,b); 
	}
	else if(nowPlayerHP > 0 && mobHP > 0 && dodge && !atk2){
		//nowPlayerHP = nowPlayerHP - mobDMG;
		mobHP = mobHP - playerDMG;
	}
	else if(nowPlayerHP > 0 && mobHP > 0 && !dodge && !atk2){
		nowPlayerHP = nowPlayerHP - mobDMG;
		mobHP = mobHP - playerDMG;
	}
	else if(nowPlayerHP <= 0){
		dead = true; 
		cout << "Player is dead" << endl;
		return;
	}
	else if(mobHP <= 0){
		cout << "Mob is dead" << endl;
		mobLootDrop(b); // return loot function DungeonRoom->get_loot()
		return;
	}

	//return i, dead;
}

Equipment *mobLootDrop(mob a){

}

#endif /* COMBAT_H_ */