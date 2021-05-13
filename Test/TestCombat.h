/*
 * TestCombat.h
 *
 *  Created on: May 10, 2021
 *      Author: patrick
 */

#ifndef TEST_TESTCOMBAT_H_
#define TEST_TESTCOMBAT_H_

#include "../Game/combat/combat.h"

void TestCombat()
{
	Player *main = new Player();
	Mob *opponent = new Mob( REG, "Goblin", DungeonTable(main->getLevel()), 1);

	Equipment *exacl = new Equipment(DMG, common, "Excalibur", 1, 200, 1);
	main->setWeapon(exacl);
	while(!combat(main, opponent));

}

#endif /* TEST_TESTCOMBAT_H_ */
