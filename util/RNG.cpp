/*
 * RNG.cpp
 *
 *  Created on: Apr 28, 2021
 *      Author: patrick
 */
#include "RNG.h"

int RANDOM_INT(int lower, int upper)
{
    std::random_device RNG;
    std::mt19937 generator(RNG());
    std::uniform_int_distribution<> distribution(lower, upper);
    return distribution(generator);
}

float RANDOM_REAL(float lower, float upper)
{
    std::random_device RNG;
    std::mt19937 generator(RNG());
    std::uniform_real_distribution<> distribution(lower, upper);
    return distribution(generator);
}


