#include <stdlib.h>
#include <time.h>
#include "Random.h"

void random::initRandomSeed()
{
    unsigned int seed = static_cast<unsigned int>(time(NULL));
    srand(seed);
}

float random::range(float a, float b)
{
    float randomValue = ((float) std::rand()) / (float) RAND_MAX;
    float difference = b - a;
    float result = randomValue * difference;
    return a + result;
}
