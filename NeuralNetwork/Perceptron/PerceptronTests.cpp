#include <fstream>
#include "../../Miscellaneous/ISerializable.h"
#include "Perceptron.h"

using namespace neuralnetwork;

void Test_Neuron_W1_greater_than_W2()
{
    const char* filePath = "C:/Projects/AIEngine/NeuralNetwork/Perceptron/data/weights_perceptron_x_greater_than_y.txt";
    random::initRandomSeed();
    std::unique_ptr<Perceptron> neuron = std::make_unique<Perceptron>(2);
    neuron->setActivationFunction(activation::sign);
    neuron->randomizeWeights();
    deserializeFromFile(filePath, *neuron);
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
    serializeToFile(filePath, *neuron);
}

void Test_Neuron_W2_greater_than_W1()
{
    const char* filePath = "C:/Projects/AIEngine/NeuralNetwork/Perceptron/data/weights_perceptron_y_greater_than_x.txt";
    random::initRandomSeed();
    std::unique_ptr<Perceptron> perceptron = std::make_unique<Perceptron>(2);
    perceptron->setActivationFunction(activation::sign);
    perceptron->randomizeWeights();
    deserializeFromFile(filePath, *perceptron);
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
    for (int i = 0; i < inputs.size(); ++i)
    {
        activation::sigmoid(inputs[i]);
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
    serializeToFile(filePath, *perceptron);
}

int main()
{
    Test_Neuron_W1_greater_than_W2();
    Test_Neuron_W2_greater_than_W1();
    return 0;
}
