/*
 * EnumerationHelpers.h
 *
 *  Created on: Apr 25, 2021
 *      Author: patrick
 */

#ifndef UTIL_ENUMERATIONHELPERS_H_
#define UTIL_ENUMERATIONHELPERS_H_

enum EqpPrefix : int
{
	perfect=1, sharp=20,
	none=80
};

enum StatType : int
{
	DEX=2, STR=3, AGI=4, MAG=0,
	ARMOR = 1, DMG = 5
};

enum Rarity : int
{
	common = 1, rare = 2,
	epic = 5, legendary = 20
};

EqpPrefix ALL_PREFIX[3] = {perfect, sharp, none};
#endif /* UTIL_ENUMERATIONHELPERS_H_ */
