#include "Random.h"

void random::initRandomSeed()
{
    unsigned int seed = static_cast<unsigned int>(time(NULL));
    srand(seed);
}

double random::range(double min, double max)
{
    double randomValue = ((double) std::rand()) / (double) RAND_MAX;
    double difference = max - min;
    double result = randomValue * difference;
    return min + result;
}
