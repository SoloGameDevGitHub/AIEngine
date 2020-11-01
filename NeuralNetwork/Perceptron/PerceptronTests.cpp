#include "Perceptron.h"
#include "../Common/Random.h"

///returns the expected output from given inputs
double toExpectedOutput(Matrix& inputs)
{
    if (inputs.get(0,0) >= inputs.get(1,0))
    {
        return -1.0;
    }
    return 1.0;
}

///Populate 'matrix' with random inputs in range -500.0/500.0
void populateRandomInput(Matrix& matrix)
{
    for (int r = 0; r < matrix.getRows(); ++r)
    {
        double value = random::range(-500.0, 500.0);
        matrix.set(r,0,value);
    }
}

int main()
{
    random::initRandomSeed();
    auto perceptron = std::make_unique<Perceptron>(2);
    perceptron->setActivationFunction(sign);
    int correctGuesses = 0;
    auto inputs = std::make_unique<Matrix>(2, 1);
    while (correctGuesses < 1000)
    {
        populateRandomInput(*inputs);
        double expectedOutput = toExpectedOutput(*inputs);
        double guess = perceptron->feedforward(*inputs);
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
    std::cout << "The network has been trained! Final weights are:" << std::endl;
    const Neuron& neuron = perceptron->getNeuron();
    const Matrix& weights = neuron.getWeights();
    weights.print(std::cout);
    std::cout << "Bias:" << neuron.getBias() << std::endl;
    return 0;
}
