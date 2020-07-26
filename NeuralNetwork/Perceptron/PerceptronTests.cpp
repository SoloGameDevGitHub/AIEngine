#include "Perceptron.h"
#include "../Common/Random.h"
#include "../Common/ActivationFunctions.h"

///returns the expected output from given inputs
float toExpectedOutput(Matrix& inputs)
{
    if (inputs.get(0,0) >= inputs.get(1,0))
    {
        return -1.0f;
    }
    return 1.0f;
}

///Populate 'matrix' with random inputs in range -500.0/500.0
void populateRandomInput(Matrix& matrix)
{
    for (int r = 0; r < matrix.getRows(); ++r)
    {
        float value = random::range(-500.0f, 500.0f);
        matrix.set(r,0,value);
    }
}

int main(int argc, char* argv[])
{
    random::initRandomSeed();
    auto perceptron = std::make_unique<Perceptron>(2);
    perceptron->setActivationFunction(sign);
    int correctGuesses = 0;
    auto inputs = std::make_unique<Matrix>(2, 1);
    while (correctGuesses < 1000)
    {
        populateRandomInput(*inputs);
        float expectedOutput = toExpectedOutput(*inputs);
        float guess = perceptron->feedforward(*inputs);
        if (guess == expectedOutput)
        {
            correctGuesses++;
        }
        else
        {
            correctGuesses = 0;
            perceptron->train(*inputs, expectedOutput);
        }
    }
    std::cout << "The network is trained!" << std::endl;
    Neuron& neuron = perceptron->getNeuron();
    Matrix& weights = neuron.getWeights();
    weights.print(std::cout);
    std::cout << "Bias:" << neuron.getBias() << std::endl;
    return 0;
}
