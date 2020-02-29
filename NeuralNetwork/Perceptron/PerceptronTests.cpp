#include "Perceptron.h"
#include "../Common/Random.h"

float sign(float value)
{
    float result = value >= 0.0f ? 1.0f : -1.0f;
    return result;
}

///returns the expected output from given inputs
float toExpectedOutput(Matrix& inputs)
{
    if (inputs.get(0,0) >= inputs.get(1,0))
    {
        return 1;
    }
    return -1;
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
    Perceptron* perceptron = new Perceptron(2);
    perceptron->setActivationFunction(sign);
    int correctGuesses = 0;
    Matrix* inputs = new Matrix(2, 1);
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
    std::cout << "The network has been trained! Final weights are:" << std::endl;
    Neuron* neuron = perceptron->getNeuron();
    neuron->getWeights()->print(std::cout);
    std::cout << "Bias:" << neuron->getBias() << std::endl;

    delete inputs;
    delete perceptron;

    return 0;
}
