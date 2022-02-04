#include <cstdlib>
#include <ctime>

#include "Random.h"

unsigned int RandomUtils::GetTime()
{
    const auto currentTime = static_cast<unsigned int>(time(nullptr));
    return currentTime;
}

void RandomUtils::InitSeed(const unsigned int seed)
{
    srand(seed);
}
