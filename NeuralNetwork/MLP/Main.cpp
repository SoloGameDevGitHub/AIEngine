#include "../ActivationFunctions.h"
#include "../../Miscellaneous/ISerializable.h"
#include "../../Miscellaneous/Random.h"
#include "../Neuron.h"
#include "MLP.h"

void initializeWeightsAndActivationFunction(MultiLayerPerceptron& mlp)
{
    for (int l = 0; l < mlp.getLayersLength(); ++l)
    {
        Layer &layer = mlp.getLayer(l);
        for (int n = 0; n < layer.getNeuronsLength(); ++n)
        {
            Neuron &neuron = layer.getNeuron(n);
            neuron.randomizeWeights();
        }
    }
}

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
    activationfunction::setThreshold(0.5);
    random::initRandomSeed();
    std::vector<int> neuronsByLayer({2,1});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.setOutputActivationFunction(activationfunction::threshold);
    initializeWeightsAndActivationFunction(mlp);
    deserializeFromFile("C:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_backpropagation_2_2_1.txt", mlp);
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
            if (iteration % 100000 == 0) initializeWeightsAndActivationFunction(mlp);
            mlp.backpropagate(inputs, expectedOutputs, 0.1);
            rightGuesses = 0;
        }
        trainingIndex++;
        trainingIndex %= trainingInputs.size();
    }
    printf("The network has been trained! (iterations: %d)\n", iteration);
    serializeToFile("C:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_backpropagation_2_2_1.txt", mlp);
}

void TEST_MLP_XOR_2_3_1()
{
    activationfunction::setThreshold(0.5);
    random::initRandomSeed();
    std::vector<int> neuronsByLayer({3,1});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.setOutputActivationFunction(activationfunction::threshold);
    initializeWeightsAndActivationFunction(mlp);
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
            if (iteration % 100000 == 0) initializeWeightsAndActivationFunction(mlp);
            mlp.backpropagate(inputs, expectedOutputs, 0.1);
            rightGuesses = 0;
        }
        trainingIndex++;
        trainingIndex %= trainingInputs.size();
    }
    printf("The network has been trained! (iterations: %d)\n", iteration);
    serializeToFile("C:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_backpropagation_2_3_1.txt", mlp);
}

void TEST_MLP_XOR_2_3_3_3_1()
{
    activationfunction::setThreshold(0.5);
    random::initRandomSeed();
    std::vector<int> neuronsByLayer({3, 3, 3, 1});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.setOutputActivationFunction(activationfunction::threshold);
    initializeWeightsAndActivationFunction(mlp);
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
            if (iteration % 100000 == 0) initializeWeightsAndActivationFunction(mlp);
            mlp.backpropagate(inputs, expectedOutputs, 0.1);
            rightGuesses = 0;
        }
        trainingIndex++;
        trainingIndex %= trainingInputs.size();
    }
    printf("The network has been trained! (iterations: %d)\n", iteration);
    serializeToFile("C:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_backpropagation_2_3_3_3_1.txt", mlp);
}

void TEST_MLP_XOR_2_3_2()
{
    activationfunction::setThreshold(0.5);
    random::initRandomSeed();
    std::vector<int> neuronsByLayer({3, 2});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.setOutputActivationFunction(activationfunction::threshold);
    initializeWeightsAndActivationFunction(mlp);
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
            if (iteration >= 100000)
            {
                initializeWeightsAndActivationFunction(mlp);
                iteration = 0;
            }
            mlp.backpropagate(inputs, expectedOutputs, 0.1);
            rightGuesses = 0;
        }
        trainingIndex++;
        trainingIndex %= trainingInputs.size();
    }
    printf("The network has been trained! (iterations: %d)\n", iteration);
    serializeToFile("C:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_backpropagation_2_2_2.txt", mlp);
}

void TEST_MLP_number_recognition_digital_clock_0_to_9()
{
    const char* filePath = "C:/Projects/AIEngine/NeuralNetwork/MLP/data/MLP weights (7;10;10) digital clock number recognition (0 to 9).txt";
    activationfunction::setThreshold(0.5);
    random::initRandomSeed();
    std::vector<int> neuronsByLayer({10, 10});
    MultiLayerPerceptron mlp(7, neuronsByLayer);
    mlp.setOutputActivationFunction(activationfunction::threshold);
    initializeWeightsAndActivationFunction(mlp);
    deserializeFromFile(filePath, mlp);
    // top -> down, left -> right
    // Digital clock numbers
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
            if (iteration % 800'000 == 0) initializeWeightsAndActivationFunction(mlp);
            mlp.backpropagate(inputs, expectedOutputs, 0.05);
            rightGuesses = 0;
        }
        trainingIndex++;
        trainingIndex %= trainingInputs.size();
    }
    printf("The network has been trained! (iterations: %d)\n", iteration);
    serializeToFile(filePath, mlp);
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
