#include "../Perceptron.h"

#include <fstream>

void Test_Neuron_W1_greater_than_W2()
{
    std::cout << __FUNCTION__ << "... ";
    RandomUtils::SetRandomSeed();
    std::unique_ptr<NeuralNetwork::Perceptron> perceptron = std::make_unique<NeuralNetwork::Perceptron>(2);
    perceptron->GetNeuron()->ActivationFunction = NeuralNetwork::Activation::EActivationFunctionType::Sign;
    perceptron->RandomizeWeights();
#ifdef PERSIST_WEIGHTS
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    Serialization::LoadWeightsFromFile(weightsFilePath.c_str(), *perceptron);
#endif

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
        double guess = perceptron->Feedforward(inputs[i]);
        if (guess != expectedOutputs[i])
        {
            iterations++;
            perceptron->Train(inputs[i], expectedOutputs[i], 0.1);
            i = -1;
        }
    }
    std::cout << "The network has been trained! (iterations: " << iterations << ")" << std::endl;
#ifdef PERSIST_WEIGHTS
    Serialization::SerializeToFile(weightsFilePath.c_str(), *perceptron);
#endif
}

void Test_Neuron_W2_greater_than_W1()
{
    std::cout << __FUNCTION__ << "... ";
    RandomUtils::SetRandomSeed();
    std::unique_ptr<NeuralNetwork::Perceptron> perceptron = std::make_unique<NeuralNetwork::Perceptron>(2);
    perceptron->GetNeuron()->ActivationFunction = NeuralNetwork::Activation::EActivationFunctionType::Sign;
    perceptron->RandomizeWeights();
#ifdef PERSIST_WEIGHTS
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    Serialization::LoadWeightsFromFile(weightsFilePath.c_str(), *perceptron);
#endif
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
        NeuralNetwork::Activation::Sigmoid(input);
    }

    for (int i = 0; i < inputs.size(); ++i)
    {
        double guess = perceptron->Feedforward(inputs[i]);
        if (guess != expectedOutputs[i])
        {
            iterations++;
            perceptron->Train(inputs[i], expectedOutputs[i], 0.1);
            i = -1;
        }
    }
    std::cout << "The network has been trained! (iterations: " << iterations << ")" << std::endl;
#ifdef PERSIST_WEIGHTS
    Serialization::SerializeToFile(weightsFilePath.c_str(), *perceptron);
#endif
}

int main()
{
    Test_Neuron_W1_greater_than_W2();
    Test_Neuron_W2_greater_than_W1();
    return 0;
}
