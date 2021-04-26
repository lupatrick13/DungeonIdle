/*
 * RNG.h
 *
 *  Created on: Apr 25, 2021
 *      Author: patrick
 */

#ifndef UTIL_RNG_H_
#define UTIL_RNG_H_

#include <random>

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

#endif /* UTIL_RNG_H_ */
