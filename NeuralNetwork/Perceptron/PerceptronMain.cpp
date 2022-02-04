#include "Perceptron.h"

#include <fstream>

using namespace NeuralNetwork;

void Test_Neuron_W1_greater_than_W2()
{
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    RandomUtils::initRandomSeed();
    std::unique_ptr<Perceptron> neuron = std::make_unique<Perceptron>(2);
    neuron->setActivationFunction(activation::sign);
    neuron->randomizeWeights();
    loadWeightsFromFile(weightsFilePath.c_str(), *neuron);
    double learningRate = 0.1;
    int iterations = 0;
    std::vector<std::vector<double>> inputs =
    {
            std::vector<double> {1.0, 0.5},    //  1.0
            std::vector<double> {0.5, 1.0},    // -1.0
            std::vector<double> {10.0, 0.0},   //  1.0
            std::vector<double> {0.0, 10.0},   // -1.0
            std::vector<double> {0.0, -10.0},  //  1.0
            std::vector<double> {-10.0, 0.0},  // -1.0
            std::vector<double> {10.0, -10.0}, //  1.0
            std::vector<double> {-10.0, 10.0}, // -1.0
            std::vector<double> {1000.0, -1000.0}, //  1.0
            std::vector<double> {-1000.0, 1000.0}, // -1.0
            std::vector<double> {351.0, -179.0}, //  1.0
            std::vector<double> {-499.8, 732.0}, // -1.0
    };
    std::vector<double> expectedOutputs = {1.0, -1.0, 1.0, -1.0, 1.0, -1.0,
                                           1.0, -1.0, 1.0, -1.0, 1.0, -1.0};
    for (int i = 0; i < inputs.size(); ++i)
    {
        double guess = neuron->feedforward(inputs[i]);
        if (guess != expectedOutputs[i])
        {
            iterations++;
            neuron->train(inputs[i], expectedOutputs[i], learningRate);
            i = -1;
        }
    }
    std::cout << "The network has been trained! (iterations: " << iterations << ")" << std::endl;
    serializeToFile(weightsFilePath.c_str(), *neuron);
}

void Test_Neuron_W2_greater_than_W1()
{
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    RandomUtils::initRandomSeed();
    std::unique_ptr<Perceptron> perceptron = std::make_unique<Perceptron>(2);
    perceptron->setActivationFunction(activation::sign);
    perceptron->randomizeWeights();
    loadWeightsFromFile(weightsFilePath.c_str(), *perceptron);
    double learningRate = 0.1;
    int iterations = 0;
    std::vector<std::vector<double>> inputs =
    {
        std::vector<double> {1.0, 0.5},    // -1.0
        std::vector<double> {0.5, 1.0},    //  1.0
        std::vector<double> {10.0, 0.0},   // -1.0
        std::vector<double> {0.0, 10.0},   //  1.0
        std::vector<double> {0.0, -10.0},  // -1.0
        std::vector<double> {-10.0, 0.0},  //  1.0
        std::vector<double> {10.0, -10.0}, // -1.0
        std::vector<double> {-10.0, 10.0}, //  1.0
    };
    std::vector<double> expectedOutputs = {-1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0};

    // apply sigmoid on inputs
    for (std::vector<double>& input : inputs)
    {
        activation::sigmoid(input);
    }

    for (int i = 0; i < inputs.size(); ++i)
    {
        double guess = perceptron->feedforward(inputs[i]);
        if (guess != expectedOutputs[i])
        {
            iterations++;
            perceptron->train(inputs[i], expectedOutputs[i], learningRate);
            i = -1;
        }
    }
    std::cout << "The network has been trained! (iterations: " << iterations << ")" << std::endl;
    serializeToFile(weightsFilePath.c_str(), *perceptron);
}

int main()
{
    Test_Neuron_W1_greater_than_W2();
    Test_Neuron_W2_greater_than_W1();
    return 0;
}
