#include "Random.h"

#include <ctime>
#include <random>

std::mt19937& GetEngine()
{
    static std::random_device randomDevice;
    static std::mt19937 engine(randomDevice());
    return engine;
}

void RandomUtils::SetRandomSeed()
{
    SetSeed(std::time(nullptr));
}

void RandomUtils::SetSeed(long long seed)
{
    GetEngine().seed(seed);
}

int RandomUtils::Range(int min, int max)
{
    std::uniform_int_distribution<> intDistribution(min, max);
    int value = intDistribution(GetEngine());
    return value;
}

double RandomUtils::Range(double min, double max)
{
    std::uniform_real_distribution<> realDistribution(min, max);
    double value = realDistribution(GetEngine());
    return value;
}

int RandomUtils::Int()
{
    std::uniform_int_distribution<> realDistribution;
    int value = realDistribution(GetEngine());
    return value;
}

double RandomUtils::Double()
{
    std::uniform_real_distribution<> realDistribution;
    double value = realDistribution(GetEngine());
    return value;
}
