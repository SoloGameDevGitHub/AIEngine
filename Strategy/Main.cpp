#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>
#include <random>

using namespace std;

struct Decision
{
	string Id;
	int Probability;
	
	Decision()
	{
		//
	};
	
	Decision(string id, int probability)
	{
		Id = id;
		Probability = probability;
	};
};

//Decision getProbability(Decision* probabilities, int size, int probability);

int main()
{
	Decision decisions[3];
	decisions[0] = Decision("ID_0", 25);
	decisions[1] = Decision("ID_1", 50);
	decisions[2] = Decision("ID_2", 25);

	int maxProbability = 0;
	for (int i = 0; i < 3; i++)
	{
		maxProbability += decisions[i].Probability;
	}
	
	std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<> dis(0, maxProbability);
	int finalProbability = dis(gen);
	Decision finalDecision;
	
	int finalProbabilityCountdown = finalProbability;
	
	for (int i = 0; i < 3; i++)
	{
		finalProbabilityCountdown -= decisions[i].Probability;
		if (finalProbabilityCountdown <= 0)
		{
			cout << finalProbability << " - " << decisions[i].Probability << endl;
			break;
		}
	}
	return 0;
};
