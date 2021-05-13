/*
 * combat.cpp
 *
 *  Created on: May 10, 2021
 *      Author: patrick
 */


#include "combat.h"

bool combat(Player *a, Mob *b, vector<std::string> *status, int num_att){
	float nowPlayerHP = a->getCurrentHP();
	float maxPlayerHP = a->getMaxHP() ;
	float playerDMG = a->combatDMG() / (num_att + 1);

	float dodgeChance = a->getDODGE();
	float dodgeChanceMob = b->getDODGE();
	bool dodge = dodgeChance > dodgeChanceMob * RANDOM_REAL(1.2, 1.8);

	float atk2Chance = a->getSPEED()/pow(2, num_att);
	float atk2ChanceMob = b->getSPEED();
	bool atk2 = atk2Chance > atk2ChanceMob * RANDOM_REAL(1.2,1.8);


	float mobHP = b->getCurrentHP();
	float mobDMG = b->combatDMG();

	float armor_reduc_player = a->getArmorReduc();
	float armor_reduc_mob = b->getArmorReduc() * 0.93;

	cout << "Player HP: " << nowPlayerHP << "/" << maxPlayerHP << endl;
	cout << "Dodge: " << dodge << "\t" << "Attack Twice: " << atk2 << endl;
	cout << b->getName() << " HP: " << mobHP << endl;

	if(nowPlayerHP > 0 && mobHP > 0){
		mobDMG *= armor_reduc_player;
		playerDMG += armor_reduc_mob;
		mobHP -= playerDMG;

		b->setCurrentHP(mobHP);
		cout << "Player hits mob for " << playerDMG<< " dmg" << endl;
		status->at(2) ="Player hits mob for " + to_string(playerDMG) + " dmg";
		if(mobHP >= 0)
		{
			if(atk2)
			{
				cout << "Player attacks twice!";
				combat(a,b, status,num_att++);
			}
			if(!dodge && !atk2)
			{
				nowPlayerHP -= mobDMG;
				cout << "Mob hits player for "<< mobDMG << " dmg" << endl;
				status->at(0) =" Mob hits player for "+ to_string(mobDMG) + " dmg" ;
				a->setCurrentHP(nowPlayerHP);
				if(nowPlayerHP <= 0)
				{
					nowPlayerHP = maxPlayerHP;
					a->setCurrentHP(maxPlayerHP);
					a->setEXP(-1 * a->getEXP() * 0.1);
				}
			}
		}
		else
		{
			int gold_gained = b->getGold();
			int exp_gained = b->getEXP();

			status->at(0) += "\nGains " + to_string(exp_gained) + " exp\n" + to_string(gold_gained) + " g";
			a->setEXP(exp_gained);
			a->setGold(gold_gained);
			a->setCurrentHP(maxPlayerHP * 0.75);
		}

	}
	cout << "Player HP: " << nowPlayerHP << "/" << maxPlayerHP << endl;
	cout << b->getName() << " HP: " << mobHP << endl << endl << endl;

	return mobHP <= 0 || nowPlayerHP<= 0;
}
