#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <ctime>

#include "../../Common/Random.h"
#include "bitset"
#include "GeneticAlgorithm.h"

// Population { [010], [1100], [1010] }
// -> Chromosome [0001]
//   -> Gene [0]

int main()
{
    RandomUtils::InitSeed(RandomUtils::GetTime());
    /*
     * 1. Initial population
     * 2. Fitness function
     * 3. Selection
     * 4. Crossover
     * 5. Mutation
     */

    GeneticAlgorithm genericAlgorithm;
    int lhs = 0xffff;
    int rhs = 0xffff << 16;

    std::cout << std::bitset<32>(lhs) << std::endl;
    std::cout << std::bitset<32>(rhs) << std::endl << std::endl;

    genericAlgorithm.Crossover(lhs, rhs, 1);

    std::cout << std::bitset<32>(lhs) << std::endl;
    std::cout << std::bitset<32>(rhs) << std::endl;

    return 0;
}
