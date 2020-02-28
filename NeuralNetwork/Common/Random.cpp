#include <stdlib.h>
#include <time.h>
#include "Random.h"

void random::initRandomSeed()
{
    srand(time(NULL));
}

float random::range(float a, float b)
{
    float random = ((float) std::rand()) / (float) RAND_MAX;
    float difference = b - a;
    float value = random * difference;
    return a + value;
}
