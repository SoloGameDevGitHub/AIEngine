#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <ctime>

#include "../../Common/Random.h"

// Population { [010], [1100], [1010] }
// -> Chromosome [0001]
//   -> Gene [0]

class GeneticAlgorithm
{
private:
    void generateInitialPopulation(std::vector<int>& population);
    int getFitnessScore(int& chromosome);
    //Order list elements based on fitness score (first == best, last == worst)
    void orderByFitnessScore(std::vector<int>& population);
    void selection(std::vector<int>& population);
    void farrow(std::vector<int>& population);
    void crossover(std::vector<int>& population);
    void mutation(std::vector<int>& population);
};

int main()
{
    random::InitSeed(random::GetTime());
    /*
     * 1. Initial population
     * 2. Fitness function
     * 3. Selection
     * 4. Crossover
     * 5. Mutation
     */
    std::cout << std::endl << "[Genetic Algorithm]" << std::endl;
    const int VECTOR_LENGTH = 10;
    std::vector<int> vector(VECTOR_LENGTH);
    for(int i = 0; i < VECTOR_LENGTH; i++)
    {
        vector[i] = random::range(0, 200);
    }
    sort(vector.begin(), vector.end());
    for(int i = 0; i < 10; i++)
    {
        std::cout << vector[i] << " ";
    }
    return 0;
}
