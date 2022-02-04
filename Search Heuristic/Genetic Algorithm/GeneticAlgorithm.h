#pragma once

#include "../../Common/Random.h"

class GeneticAlgorithm
{
public:
    void Crossover(int& lhs, int& rhs, const int index)
    {
        const int leftMask = 0xffffffff >> index;
        const int rightMask = ~leftMask;

        const int newLhs = (lhs & leftMask) | (rhs & rightMask);
        const int newRhs = (rhs & leftMask) | (lhs & rightMask);

        lhs = newLhs;
        rhs = newRhs;
    }

    void Mutate(int& chromossome)
    {
        for (int i = 0; i < 32; i++)
        {
            if (RandomUtils::range(0.0, 1.0) > 0.001) continue;
            const int geneMask = 1 << i;

            //TODO
        }
    }

    //void generateInitialPopulation(std::vector<int>& population);
    //int getFitnessScore(int& chromosome);
    //Order list elements based on fitness score (first == best, last == worst)
    //void orderByFitnessScore(std::vector<int>& population);
    //void selection(std::vector<int>& population);
    //void farrow(std::vector<int>& population);
    //void crossover(std::vector<int>& population);
    //void mutation(std::vector<int>& population);
};
