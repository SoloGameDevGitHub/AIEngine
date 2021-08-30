#include "../ActivationFunctions.h"
#include "../../Miscellaneous/ISerializable.h"
#include "../../Miscellaneous/Random.h"
#include "../Neuron.h"
#include "MLP.h"

using namespace neuralnetwork;

bool equals(const std::vector<double>& lhs, const std::vector<double>& rhs)
{
    for (int i = 0; i < lhs.size(); ++i)
    {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}

void TEST_MLP_XOR_2_2_1()
{
    const char* filePath = "C:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_backpropagation_2_2_1.txt";
    activation::setThreshold(0.7);
    random::initRandomSeed();
    std::vector<int> neuronsByLayer({2,1});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.setActivationFunction(activation::threshold);
    mlp.randomizeWeights(mlp);
    deserializeFromFile(filePath, mlp);
    std::vector<std::vector<double>> trainingInputs = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::vector<double>> trainingOutputs = { {0.0}, {1.0}, {1.0}, {0.0} };
    long iteration = 0L;
    int trainingIndex = 0;
    int rightGuesses = 0;
    while (rightGuesses < trainingInputs.size())
    {
        std::vector<double>& inputs = trainingInputs[trainingIndex];
        std::vector<double>& expectedOutputs = trainingOutputs[trainingIndex];
        std::vector<double> outputs = mlp.feedforward(inputs);
        if (equals(outputs, expectedOutputs))
        {
            rightGuesses++;
        }
        else
        {
            iteration++;
            mlp.backpropagate(inputs, expectedOutputs, 0.01);
            rightGuesses = 0;
        }
        trainingIndex++;
        trainingIndex %= trainingInputs.size();
    }
    printf("The network has been trained! (iterations: %d)\n", iteration);
    saveWeightsIntoFile(filePath, mlp);
}

void TEST_MLP_XOR_2_3_1()
{
    activation::setThreshold(0.7);
    random::initRandomSeed();
    std::vector<int> neuronsByLayer({3,1});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.setActivationFunction(activation::threshold);
    mlp.randomizeWeights(mlp);
    deserializeFromFile("C:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_backpropagation_2_3_1.txt", mlp);
    std::vector<std::vector<double>> trainingInputs = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::vector<double>> trainingOutputs = { {0.0}, {1.0}, {1.0}, {0.0} };
    long iteration = 0L;
    int trainingIndex = 0;
    int rightGuesses = 0;
    while (rightGuesses < trainingInputs.size())
    {
        std::vector<double>& inputs = trainingInputs[trainingIndex];
        std::vector<double>& expectedOutputs = trainingOutputs[trainingIndex];
        std::vector<double> outputs = mlp.feedforward(inputs);
        if (equals(outputs, expectedOutputs))
        {
            rightGuesses++;
        }
        else
        {
            iteration++;
            mlp.backpropagate(inputs, expectedOutputs, 0.01);
            rightGuesses = 0;
        }
        trainingIndex++;
        trainingIndex %= trainingInputs.size();
    }
    printf("The network has been trained! (iterations: %d)\n", iteration);
    saveWeightsIntoFile("C:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_backpropagation_2_3_1.txt", mlp);
}

void TEST_MLP_XOR_2_3_3_3_1()
{
    activation::setThreshold(0.7);
    random::initRandomSeed();
    std::vector<int> neuronsByLayer({3, 3, 3, 1});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.setActivationFunction(activation::threshold);
    mlp.randomizeWeights(mlp);
    deserializeFromFile("C:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_backpropagation_2_3_3_3_1.txt", mlp);
    std::vector<std::vector<double>> trainingInputs = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::vector<double>> trainingOutputs = { {0.0}, {1.0}, {1.0}, {0.0} };
    long iteration = 0L;
    int trainingIndex = 0;
    int rightGuesses = 0;
    while (rightGuesses < trainingInputs.size())
    {
        std::vector<double>& inputs = trainingInputs[trainingIndex];
        std::vector<double> expectedOutputs = trainingOutputs[trainingIndex];
        std::vector<double> outputs = mlp.feedforward(inputs);
        if (equals(outputs, expectedOutputs))
        {
            rightGuesses++;
        }
        else
        {
            iteration++;
            mlp.backpropagate(inputs, expectedOutputs, 0.01);
            rightGuesses = 0;
        }
        trainingIndex++;
        trainingIndex %= trainingInputs.size();
    }
    printf("The network has been trained! (iterations: %d)\n", iteration);
    saveWeightsIntoFile("C:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_backpropagation_2_3_3_3_1.txt", mlp);
}

void TEST_MLP_XOR_2_3_2()
{
    activation::setThreshold(0.7);
    random::initRandomSeed();
    std::vector<int> neuronsByLayer({3, 2});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.setActivationFunction(activation::threshold);
    mlp.randomizeWeights(mlp);
    deserializeFromFile("C:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_backpropagation_2_2_2.txt", mlp);
    std::vector<std::vector<double>> trainingInputs = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::vector<double>> trainingOutputs = {  {1.0, 0.0}, {0.0, 1.0}, {0.0, 1.0}, {1.0, 0.0} };
    long iteration = 0L;
    int trainingIndex = 0;
    int rightGuesses = 0;
    while (rightGuesses < trainingInputs.size())
    {
        std::vector<double>& inputs = trainingInputs[trainingIndex];
        std::vector<double>& expectedOutputs = trainingOutputs[trainingIndex];
        std::vector<double> outputs = mlp.feedforward(inputs);
        if (equals(outputs, expectedOutputs))
        {
            rightGuesses++;
        }
        else
        {
            iteration++;
            mlp.backpropagate(inputs, expectedOutputs, 0.01);
            rightGuesses = 0;
        }
        trainingIndex++;
        trainingIndex %= trainingInputs.size();
    }
    printf("The network has been trained! (iterations: %d)\n", iteration);
    saveWeightsIntoFile("C:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_backpropagation_2_2_2.txt", mlp);
}

void TEST_MLP_number_recognition_digital_clock_0_to_9()
{
    const char* filePath = "C:/Projects/AIEngine/NeuralNetwork/MLP/data/MLP weights (7;10;10) digital clock number recognition (0 to 9).txt";
    activation::setThreshold(0.7);
    random::initRandomSeed();
    std::vector<int> neuronsByLayer({10, 10});
    MultiLayerPerceptron mlp(7, neuronsByLayer);
    mlp.setActivationFunction(activation::threshold);
    mlp.randomizeWeights(mlp);
    deserializeFromFile(filePath, mlp);
    std::vector<std::vector<double>> trainingInputs =
    {
        { 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0 }, //0
        { 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0 }, //1
        { 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0 }, //2
        { 1.0, 0.0, 1.0, 1.0, 0.0, 1.0, 1.0 }, //3
        { 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0 }, //4
        { 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0 }, //5
        { 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0 }, //6
        { 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0 }, //7
        { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }, //8
        { 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0 }, //9
    };
    std::vector<std::vector<double>> trainingOutputs =
    {
            { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
            { 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
            { 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
            { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
            { 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
            { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },
            { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 },
            { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 },
            { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
            { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },
    };
    long iteration = 0L;
    int trainingIndex = 0;
    int rightGuesses = 0;
    do
    {
        std::vector<double>& inputs = trainingInputs[trainingIndex];
        std::vector<double>& expectedOutputs = trainingOutputs[trainingIndex];
        std::vector<double> outputs = mlp.feedforward(inputs);
        if (equals(outputs, expectedOutputs))
        {
            rightGuesses++;
        }
        else
        {
            iteration++;
            rightGuesses = 0;
            mlp.backpropagate(inputs, expectedOutputs, 0.01);
        }
        trainingIndex++;
        trainingIndex %= trainingInputs.size();
    }
    while (rightGuesses < trainingInputs.size());
    printf("The network has been trained! (iterations: %d)\n", iteration);
    saveWeightsIntoFile(filePath, mlp);
}

int main()
{
    TEST_MLP_XOR_2_2_1();
    TEST_MLP_XOR_2_3_1();
    TEST_MLP_XOR_2_3_3_3_1();
    TEST_MLP_XOR_2_3_2();
    TEST_MLP_number_recognition_digital_clock_0_to_9();
    return 0;
}
