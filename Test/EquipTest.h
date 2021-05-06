/*
 * EquipTest.h
 *
 *  Created on: Apr 24, 2021
 *      Author: patrick
 */

#ifndef TEST_EQUIPTEST_H_
#define TEST_EQUIPTEST_H_

#include "../Game/Equipment/EqpDecoratorP.h"

using namespace std;

void equip_test()
{
	Equipment *AmazingSword = new Equipment(DMG, legendary, "Excalibur", 1000, 200, 999);

	AmazingSword->print();

	cout << endl << endl;
	AmazingSword = new Perfect(AmazingSword);

	AmazingSword->print();
	cout << endl << endl;
	AmazingSword = new Sharp(AmazingSword);

	AmazingSword->print();


}



#endif /* TEST_EQUIPTEST_H_ */
