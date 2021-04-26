/*
 * EnumConverters.h
 *
 *  Created on: Apr 25, 2021
 *      Author: patrick
 */

#ifndef UTIL_ENUMCONVERTERS_H_
#define UTIL_ENUMCONVERTERS_H_

#include "EnumerationHelpers.h"
#include "string"

std::string GET_TYPE(int type)
{
	switch(type)
	{
	case ARMOR:
		return "ARMOR";
	case DEX:
		return "DEX";
	case STR:
		return "STR";
	case AGI:
		return "AGI";
	case MAG:
		return "MAG";
	case DMG:
		return "DMG";
	}
	return "DMG";
}

std::string GET_RARITY(Rarity rarity)
{
	switch(rarity)
	{
	case common:
		return "common";
	case rare:
		return "rare";
	case epic:
		return "epic";
	case legendary:
		return "legendary";
	}
	return "common";
}

#endif /* UTIL_ENUMCONVERTERS_H_ */
