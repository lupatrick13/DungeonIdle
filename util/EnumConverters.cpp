/*
 * EnumConverters.cpp
 *
 *  Created on: Apr 28, 2021
 *      Author: patrick
 */

#include "EnumConverters.h"

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

wxColour *RARITY_COLOUR(Rarity rarity)
{
	switch(rarity)
	{
	case common:
		return new wxColour(255, 255, 255);
	case rare:
		return new wxColour(64, 90, 255);
	case epic:
		return new wxColour(186, 64, 255);
	case legendary:
		return new wxColour(255, 230, 64);
	}
	return new wxColour(255, 255, 255);
}
