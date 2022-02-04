#include <cstring>
#include "MLP.h"

using namespace NeuralNetwork;

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
    std::cout << __FUNCTION__ << "... ";
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    activation::setThreshold(0.7);
    RandomUtils::initRandomSeed();
    std::vector<int> neuronsByLayer({2,1});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.setActivationFunction(activation::threshold);
    mlp.randomizeWeights(mlp);
    loadWeightsFromFile(weightsFilePath.c_str(), mlp);
    std::vector<std::vector<double>> trainingInputs = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::vector<double>> trainingOutputs = { {0.0}, {1.0}, {1.0}, {0.0} };
    long iteration = 0L;
    size_t trainingIndex = 0;
    size_t rightGuesses = 0;
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
    printf("The network has been trained in '%l' iterations.\n", iteration);
    serializeToFile(weightsFilePath.c_str(), mlp);
}

void TEST_MLP_XOR_2_3_1()
{
    std::cout << __FUNCTION__ << "... ";
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    activation::setThreshold(0.7);
    RandomUtils::initRandomSeed();
    std::vector<int> neuronsByLayer({3,1});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.setActivationFunction(activation::threshold);
    mlp.randomizeWeights(mlp);
    loadWeightsFromFile(weightsFilePath.c_str(), mlp);
    std::vector<std::vector<double>> trainingInputs = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::vector<double>> trainingOutputs = { {0.0}, {1.0}, {1.0}, {0.0} };
    long iteration = 0L;
    size_t trainingIndex = 0;
    size_t rightGuesses = 0;
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
    printf("The network has been trained in '%l' iterations.\n", iteration);
    serializeToFile(weightsFilePath.c_str(), mlp);
}

void TEST_MLP_XOR_2_3_3_3_1()
{
    std::cout << __FUNCTION__ << "... ";
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    activation::setThreshold(0.7);
    RandomUtils::initRandomSeed();
    std::vector<int> neuronsByLayer({3, 3, 3, 1});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.setActivationFunction(activation::threshold);
    mlp.randomizeWeights(mlp);
    loadWeightsFromFile(weightsFilePath.c_str(), mlp);
    std::vector<std::vector<double>> trainingInputs = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::vector<double>> trainingOutputs = { {0.0}, {1.0}, {1.0}, {0.0} };
    long iteration = 0L;
    size_t trainingIndex = 0;
    size_t rightGuesses = 0;
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
    printf("The network has been trained in '%l' iterations.\n", iteration);
    serializeToFile(weightsFilePath.c_str(), mlp);
}

void TEST_MLP_XOR_2_3_2()
{
    std::cout << __FUNCTION__ << "... ";
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    activation::setThreshold(0.7);
    RandomUtils::initRandomSeed();
    std::vector<int> neuronsByLayer({3, 2});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.setActivationFunction(activation::threshold);
    mlp.randomizeWeights(mlp);
    loadWeightsFromFile(weightsFilePath.c_str(), mlp);
    std::vector<std::vector<double>> trainingInputs = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::vector<double>> trainingOutputs = {  {1.0, 0.0}, {0.0, 1.0}, {0.0, 1.0}, {1.0, 0.0} };
    long iteration = 0L;
    size_t trainingIndex = 0;
    size_t rightGuesses = 0;
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
    printf("The network has been trained in '%l' iterations.\n", iteration);
    serializeToFile(weightsFilePath.c_str(), mlp);
}

void TEST_MLP_number_recognition_digital_clock_0_to_9()
{
    std::cout << __FUNCTION__ << "... ";
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    activation::setThreshold(0.7);
    RandomUtils::initRandomSeed();
    std::vector<int> neuronsByLayer({10, 10});
    MultiLayerPerceptron mlp(7, neuronsByLayer);
    mlp.setActivationFunction(activation::threshold);
    mlp.randomizeWeights(mlp);
    loadWeightsFromFile(weightsFilePath.c_str(), mlp);
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
    size_t trainingIndex = 0;
    size_t rightGuesses = 0;
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
    printf("The network has been trained in '%l' iterations.\n", iteration);
    serializeToFile(weightsFilePath.c_str(), mlp);
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
