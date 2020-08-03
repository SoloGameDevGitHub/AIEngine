#include <iostream>
#include <fstream>
#include "../Common/Random.h"
#include "MLP.h"

int propagate(MultiLayerPerceptron& mlp, std::vector<float> inputs, bool printResult)
{
    std::unique_ptr<Matrix> inputsMatrix = std::make_unique<Matrix>(2, 1);
    inputsMatrix->set(0, 0, inputs[0]);
    inputsMatrix->set(1, 0, inputs[1]);
    mlp.feedforward(*inputsMatrix);
    const Matrix& outputs = mlp.getOutputs();
    if (printResult)
    {
        outputs.print(std::cout, 2);
    }
    int value = outputs.get(0, 0);
    return value;
}

void saveWeightsInFile(const char* filePath, MultiLayerPerceptron& mlp)
{
    std::fstream myfile;
    myfile.open (filePath);
    mlp.print(myfile);
    myfile.close();
}

void loadWeightsFromFile(const char* filePath, MultiLayerPerceptron& mlp)
{
    std::fstream myfile;
    myfile.open (filePath);
    mlp.recover(myfile);
    myfile.close();
}

void trainXor2LayersMLP(const char* filePath)
{
    std::cout << "XOR - 2 Layers (2, 1)" << std::endl;
    random::initRandomSeed();
    std::vector<int> neuronsByLayerArr = std::vector<int> {2,1};
    bool isNetworkTrained = false;
    unsigned long iterations = 0;
    setZeroOrOneThreshold(0.5f);
    std::vector<float> inputs00 = std::vector<float>{0.0f, 0.0f};
    std::vector<float> inputs10 = std::vector<float>{1.0f, 0.0f};
    std::vector<float> inputs01 = std::vector<float>{0.0f, 1.0f};
    std::vector<float> inputs11 = std::vector<float>{1.0f, 1.0f};
    while(!isNetworkTrained)
    {
        iterations++;
        MultiLayerPerceptron mlp(neuronsByLayerArr);
        loadWeightsFromFile(filePath, mlp);
        mlp.setOutputActivationFunction(zeroOrOne);
        if (propagate(mlp, inputs00, false) != 0.0f) continue;
        if (propagate(mlp, inputs10, false) != 1.0f) continue;
        if (propagate(mlp, inputs01, false) != 1.0f) continue;
        if (propagate(mlp, inputs11, false) != 0.0f) continue;
        isNetworkTrained = true;
        saveWeightsInFile(filePath, mlp);
    }
    std::cout << "It's trained, bro! :D   (iterations: " << iterations << ")" << std::endl;
}

void trainXor3LayersMLP(const char* filePath)
{
    std::cout << "XOR - 3 Layers (2, 2, 1)" << std::endl;
    random::initRandomSeed();
    std::vector<int> neuronsByLayerArr = std::vector<int> {2,2,1};
    bool isNetworkTrained = false;
    unsigned long iterations = 0;
    setZeroOrOneThreshold(0.5f);
    std::vector<float> inputs00 = std::vector<float>{0.0f, 0.0f};
    std::vector<float> inputs10 = std::vector<float>{1.0f, 0.0f};
    std::vector<float> inputs01 = std::vector<float>{0.0f, 1.0f};
    std::vector<float> inputs11 = std::vector<float>{1.0f, 1.0f};
    while(!isNetworkTrained)
    {
        iterations++;
        MultiLayerPerceptron mlp(neuronsByLayerArr);
        loadWeightsFromFile(filePath, mlp);
        mlp.setOutputActivationFunction(zeroOrOne);
        if (propagate(mlp, inputs00, false) != 0.0f) continue;
        if (propagate(mlp, inputs10, false) != 1.0f) continue;
        if (propagate(mlp, inputs01, false) != 1.0f) continue;
        if (propagate(mlp, inputs11, false) != 0.0f) continue;
        isNetworkTrained = true;
        saveWeightsInFile(filePath, mlp);
    }
    std::cout << "It's trained, bro! :D   (iterations: " << iterations << ")" << std::endl;
}

int main()
{
    trainXor2LayersMLP("D:/Projects/AIEngine/NeuralNetwork/MLP/data/weights.txt");
    trainXor3LayersMLP("D:/Projects/AIEngine/NeuralNetwork/MLP/data/xor_weights_3_layers.txt");
    return 0;
}
