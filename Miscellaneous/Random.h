#pragma once

namespace RandomUtils
{
    // seed
    void SetRandomSeed();
    void SetSeed(long long seed);

    // random fixed and floating point values
    int Int();
    double Double();

    // range of values
    int Range(int min, int max);
    double Range(double min, double max);
}
