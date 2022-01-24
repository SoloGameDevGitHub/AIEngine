#include <cstdlib>
#include <ctime>

#include "Random.h"

unsigned int random::GetTime()
{
    const auto currentTime = static_cast<unsigned int>(time(nullptr));
    return currentTime;
}

void random::InitSeed(const unsigned int seed)
{
    srand(seed);
}
