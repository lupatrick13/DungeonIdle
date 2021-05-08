/*
 * EnumConverters.h
 *
 *  Created on: Apr 25, 2021
 *      Author: patrick
 */

#ifndef UTIL_ENUMCONVERTERS_H_
#define UTIL_ENUMCONVERTERS_H_

#include "EnumerationHelpers.h"
#include <string>
#include <wx/colour.h>

std::string GET_TYPE(int type);
std::string GET_RARITY(Rarity rarity);
wxColour *RARITY_COLOUR(Rarity rarity);

#endif /* UTIL_ENUMCONVERTERS_H_ */
