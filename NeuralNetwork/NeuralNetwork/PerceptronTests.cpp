#include "Perceptron.h"

using namespace std;

///returns the expected output from given inputs
float toExpectedOutput(Matrix*& inputs)
{
    if (inputs->get(0,0) >= inputs->get(1,0))
    {
        return 1;
    }
    return -1;
}

///Populate 'matrix' with random inputs in range -500.0/500.0
void populateRandomInput(Matrix*& matrix)
{
    for (int r = 0; r < matrix->getRows(); ++r)
    {
        matrix->set(r,0,(float(rand())/float((RAND_MAX)) * 1000.0f) - 500.0f);
    }
}

int main(int argc, char* argv[])
{
    srand((unsigned int)time(NULL));
    Perceptron* perceptron = new Perceptron(2);
    int correctGuesses = 0;
    Matrix* inputs = new Matrix(2, 1);
    while (correctGuesses < 1000)
    {
        populateRandomInput(inputs);
        float expectedOutput = toExpectedOutput(inputs);
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
    cout << "The network has been trained! Final weights are:" << endl;
    Neuron* neuron = perceptron->getNeuron();
    neuron->getWeights()->print(cout);
    cout << "Bias:" << neuron->getBias() << endl;

    delete inputs;
    delete perceptron;

    return 0;
}
