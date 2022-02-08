#include "Random.h"

void RandomUtils::initRandomSeed()
{
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
}

double RandomUtils::range(double min, double max)
{
    double randomValue = ((double) std::rand()) / (double) RAND_MAX;
    double difference = max - min;
    double result = randomValue * difference;
    return min + result;
}
