#include <iostream>
#include <fstream>
#include "../Common/Random.h"
#include "MLP.h"

bool feedfoward(const MultiLayerPerceptron& mlp, const std::vector<double>& inputs, const std::vector<double>& expectedOutputs, bool printResult)
{
    std::unique_ptr<Matrix> inputsMatrix = Matrix::fromVectorRows(inputs);
    mlp.feedforward(*inputsMatrix);
    const Matrix& outputs = mlp.getOutputs();
    if (printResult)
    {
        outputs.print(std::cout, 2);
    }
    for (int i = 0; i < expectedOutputs.size(); ++i)
    {
        const double actualOutput = outputs.get(i, 0);
        const double expectedOutput = expectedOutputs[i];
        if (actualOutput != expectedOutput)
            return false;
    }
    return true;
}

void saveWeightsInFile(const char* filePath, const MultiLayerPerceptron& mlp)
{
    std::fstream myfile;
    myfile.open (filePath);
    mlp.print(myfile);
    myfile.close();
}

void loadWeightsFromFile(const char* filePath, const MultiLayerPerceptron& mlp)
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
    setZeroOrOneThreshold(0.5);

    std::vector<double> inputs00 = std::vector<double>{0.0, 0.0};
    std::vector<double> inputs10 = std::vector<double>{1.0, 0.0};
    std::vector<double> inputs01 = std::vector<double>{0.0, 1.0};
    std::vector<double> inputs11 = std::vector<double>{1.0, 1.0};

    std::vector<double> output0 = std::vector<double>{0.0};
    std::vector<double> output1 = std::vector<double>{1.0};

    while(!isNetworkTrained)
    {
        iterations++;
        MultiLayerPerceptron mlp(neuronsByLayerArr);
        loadWeightsFromFile(filePath, mlp);
        mlp.setOutputActivationFunction(zeroOrOne);
        if (!feedfoward(mlp, inputs00, output0, false)) continue;
        if (!feedfoward(mlp, inputs10, output1, false)) continue;
        if (!feedfoward(mlp, inputs01, output1, false)) continue;
        if (!feedfoward(mlp, inputs11, output0, false)) continue;
        isNetworkTrained = true;
        saveWeightsInFile(filePath, mlp);
    }
    std::cout << "It's trained, bro! :D   (iterations: " << iterations << ")" << std::endl;
}

void backpropagateXor2LayersMLP(const char* filePath)
{
    std::cout << "XOR - 2 Layers (2, 1)" << std::endl;
    random::initRandomSeed();
    std::vector<int> neuronsByLayerArr = std::vector<int> {2,1};
    bool isNetworkTrained = false;
    unsigned long iterations = 0;
    setZeroOrOneThreshold(0.5);

    std::vector<double> inputs00 = std::vector<double>{0.0, 0.0};
    std::vector<double> inputs10 = std::vector<double>{1.0, 0.0};
    std::vector<double> inputs01 = std::vector<double>{0.0, 1.0};
    std::vector<double> inputs11 = std::vector<double>{1.0, 1.0};

    std::vector<double> output0 = std::vector<double>{0.0};
    std::vector<double> output1 = std::vector<double>{1.0};

    MultiLayerPerceptron mlp(neuronsByLayerArr);

    double learningRate = 0.1;

    while(!isNetworkTrained)
    {
        iterations++;
        //loadWeightsFromFile(filePath, mlp);
        mlp.setOutputActivationFunction(zeroOrOne);
        if (!feedfoward(mlp, inputs00, output0, false))
        {
            mlp.backpropagate(inputs00, output0, learningRate);
            continue;
        }
        if (!feedfoward(mlp, inputs10, output1, false))
        {
            mlp.backpropagate(inputs10, output1, learningRate);
            continue;
        }
        if (!feedfoward(mlp, inputs01, output1, false))
        {
            mlp.backpropagate(inputs01, output1, learningRate);
            continue;
        }
        if (!feedfoward(mlp, inputs11, output0, false))
        {
            mlp.backpropagate(inputs11, output0, learningRate);
            continue;
        }
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

    setZeroOrOneThreshold(0.5);

    std::vector<double> inputs00 = std::vector<double>{0.0, 0.0};
    std::vector<double> inputs10 = std::vector<double>{1.0, 0.0};
    std::vector<double> inputs01 = std::vector<double>{0.0, 1.0};
    std::vector<double> inputs11 = std::vector<double>{1.0, 1.0};

    std::vector<double> output0 = std::vector<double>{0.0};
    std::vector<double> output1 = std::vector<double>{1.0};

    while(!isNetworkTrained)
    {
        iterations++;
        MultiLayerPerceptron mlp(neuronsByLayerArr);
        loadWeightsFromFile(filePath, mlp);
        mlp.setOutputActivationFunction(zeroOrOne);
        if (!feedfoward(mlp, inputs00, output0, false)) continue;
        if (!feedfoward(mlp, inputs10, output1, false)) continue;
        if (!feedfoward(mlp, inputs01, output1, false)) continue;
        if (!feedfoward(mlp, inputs11, output0, false)) continue;
        isNetworkTrained = true;
        saveWeightsInFile(filePath, mlp);
    }
    std::cout << "It's trained, bro! :D   (iterations: " << iterations << ")" << std::endl;
}

void backpropagationExampleFromBook()
{
    std::vector<int> neuronsByLayer = {2, 2};
    MultiLayerPerceptron mlp(neuronsByLayer);

    const Layer& inputLayer = mlp.getLayer(0);
    const Layer& outputLayer = mlp.getLayer(0);

    /* hiddenLayer[0]
     *     perceptron[0] (input weights)
     *     perceptron[1] (input weights)
     */

     /* outputLayer[1]
     *     perceptron[0] (hidden weights)
     *     perceptron[1] (hidden weights)
     */
}

int main()
{
    trainXor2LayersMLP("C:/Projects/weights.txt");
    //backpropagationExampleFromBook();
    return 0;
    double expectedOutput = 1.0;
    double actualOutput = 0.2;
    double error = (expectedOutput - actualOutput); // 0.8

    double hiddenWeight1 = 2.0;
    double hiddenWeight2 = 3.0;

    //trainXor2LayersMLP("C:/Projects/weights.txt");
    //trainXor3LayersMLP("C:/Projects/xor_weights_3_layers.txt");
    return 0;
}
