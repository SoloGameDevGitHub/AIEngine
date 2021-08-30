#include <fstream>
#include <bits/stdc++.h>
#include "../../Miscellaneous/ISerializable.h"
#include "Perceptron.h"

using namespace neuralnetwork;

static std::string GetAbsolutePath(const char* relativePath)
{
    const char* rawRootPath = getenv("PROJECTS_PATH");
    std::string absolutePath = std::string(rawRootPath) + std::string("/AIEngine/") + std::string(relativePath);
    return absolutePath;
}

void Test_Neuron_W1_greater_than_W2()
{
    random::initRandomSeed();
    std::unique_ptr<Perceptron> neuron = std::make_unique<Perceptron>(2);
    neuron->setActivationFunction(activation::sign);
    neuron->randomizeWeights();
    std::string filePath = GetAbsolutePath("NeuralNetwork/Perceptron/data/weights_perceptron_x_greater_than_y.txt");
    deserializeFromFile(filePath.c_str(), *neuron);
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
    saveWeightsIntoFile(filePath.c_str(), *neuron);
}

void Test_Neuron_W2_greater_than_W1()
{
    random::initRandomSeed();
    std::unique_ptr<Perceptron> perceptron = std::make_unique<Perceptron>(2);
    perceptron->setActivationFunction(activation::sign);
    perceptron->randomizeWeights();
    std::string filePath = GetAbsolutePath("NeuralNetwork/Perceptron/data/weights_perceptron_y_greater_than_x.txt");
    deserializeFromFile(filePath.c_str(), *perceptron);
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
    std::vector<double> expectedOutputs =
    {
            -1.0,
            1.0,
            -1.0,
            1.0,
            -1.0,
            1.0,
            -1.0,
            1.0
    };

    // run training iterations until the network has been trained
    int iterations = 0;
    for (int index = 0; index < inputs.size(); ++index)
    {
        double guess = perceptron->feedforward(inputs[index]);

        if (guess != expectedOutputs[index])
        {
            // train network
            iterations++;
            perceptron->train(inputs[index], expectedOutputs[index], 0.1);
            index = -1;
        }
    }

    std::cout << "The network has been trained! (iterations: " << iterations << ")" << std::endl;

    saveWeightsIntoFile(filePath.c_str(), *perceptron);
}

int main()
{
    Test_Neuron_W1_greater_than_W2();
    Test_Neuron_W2_greater_than_W1();
    return 0;
}
