#ifndef COMBAT_H_
#define COMBAT_H_

#include "../Entity/entity.h"
#include "../Entity/player.h"
#include "../Entity/mob.h"

using namespace std;

bool combat(Player *a, Mob *b){
	bool dead = false;
	int i = 0;

	int nowPlayerHP = a->getCurrentHP();
	int maxPlayerHP = a->getMaxHP() ;
	int playerDMG = a->combatDMG();
	
	int dodgeChance = a->getDODGE();
	bool dodge = dodgeChance * RANDOM_INT(1,5) > 100; 
	
	int atk2Chance = a->getSPEED();
	bool atk2 = atk2Chance * RANDOM_INT(1,5) > 100;
	

	int mobHP = b->getCurrentHP();
	int mobDMG = b->combatDMG();

	cout << "Player HP: " << nowPlayerHP << "/" << maxPlayerHP << endl;
	cout << "Player DMG: " << playerDMG << endl;
	cout << "Dodge: " << dodge << "\t" << "Attack Twice: " << atk2 << endl;
	cout << "Mob HP: " << mobHP << endl;
	cout << "Mob DMG: " << mobDMG << endl;

	if(nowPlayerHP > 0 && mobHP > 0){	
			if(dodge && atk2){
				//nowPlayerHP = nowPlayerHP - mobDMG;
				//mobHP = mobHP - 2 * playerDMG;
				b->setCurrentHP(mobHP - playerDMG);
				cout << "Player attacked Mob for " << playerDMG << "DMG." << endl;
				cout << "Mob HP: " << b->getCurrentHP();
				cout << "Player dodges Mob attack. " << endl;
				cout << "Player gets to attack twice. " << endl;
				combat(a, b);
				
			}
			else if(!dodge && atk2){
				
				//mobHP = mobHP - 2 * playerDMG;
				b->setCurrentHP(mobHP - playerDMG);
				cout << "Player attacked Mob for " << playerDMG << "DMG." << endl;
				cout << "Mob HP: " << b->getCurrentHP();
				if(b->getCurrentHP() > 0){
					a->setCurrentHP(nowPlayerHP - mobDMG);
				}
				cout << "Mob attacked Player for " << mobDMG << "DMG." << endl;
				cout << "Player HP: " << a->getCurrentHP();
				cout << "Player gets to attack twice. " << endl;
				combat(a,b); 
			}
			else if(dodge && !atk2){
				//nowPlayerHP = nowPlayerHP - mobDMG;
				b->setCurrentHP(mobHP - playerDMG);
				cout << "Player attacked Mob for " << playerDMG << "DMG." << endl;
				cout << "Mob HP: " << b->getCurrentHP();
				cout << "Player dodges Mob attack. " << endl;
			}
			
			else if(!dodge && !atk2){
				b->setCurrentHP(mobHP - playerDMG);
				cout << "Player attacked Mob for " << playerDMG << "DMG." << endl;
				cout << "Mob HP: " << b->getCurrentHP();
				if(b->getCurrentHP() > 0){
					a->setCurrentHP(nowPlayerHP - mobDMG);
				}
				cout << "Mob attacked Player for " << mobDMG << "DMG." << endl;
				cout << "Player HP: " << a->getCurrentHP();
		
			}
	}
	else{
		if(nowPlayerHP <= 0){
			dead = true; 
			cout << "Player is dead" << endl;
			return dead;
		}
		else if(mobHP <= 0){
			cout << "Mob is dead" << endl;
			//mobLootDrop(b); // return loot function DungeonRoom->get_loot()
			return dead;
		}
	}
	
	return dead;
	//return i, dead;
}

// Equipment *mobLootDrop(mob a){

// }

#endif /* COMBAT_H_ */