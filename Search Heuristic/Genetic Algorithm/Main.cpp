#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef float (*FitnessFunction)(float);

void selectedSorting()
{
    //TODO
}

class GeneticAlgorithm
{
private:
    void generateInitialPopulation(vector<int> &data);
    int getFitnessScore(int &data);
    //Order list elements based on fitness score (first == best, last == worst)
    void orderByFitnessScore(vector<int> &data, FitnessFunction &fitnessFunction);
    void selection(vector<int> &data);
    void farrow(vector<int> &data);
    void crossover(vector<int> &data);
    void mutation(vector<int> &data);
};

int main()
{
    /*
     * 1. Initial population
     * 2. Fitness function
     * 3. Selection
     * 4. Crossover
     * 5. Mutation
     */
    vector<int> asd;
    for(int i = 0; i < 10; i++)
    {
        int number = i % 3;
        asd.push_back(number);
    }
    sort(asd.begin(), asd.end());
    for(int i = 0; i < 10; i++)
    {
        cout << asd[i] << " ";
    }
    cout << endl << "[Genetic Algorithm]" << endl;
    return 0;
}
