#include "../MLP.h"

#include <cstring>

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

void ApplySupervisedLearning(MultiLayerPerceptron& mlp,
                  // training inputs and outputs
                  const std::vector<std::vector<double>>& trainingInputs,
                  const std::vector<std::vector<double>>& trainingOutputs)
{
    size_t totalIterations = 0L;
    size_t iteration = 0L;
    size_t trainingIndex = 0;
    size_t rightGuesses = 0;

    while (rightGuesses < trainingInputs.size())
    {
        const std::vector<double>& inputs = trainingInputs[trainingIndex];
        const std::vector<double>& expectedOutputs = trainingOutputs[trainingIndex];
        const std::vector<double> outputs = mlp.Feedforward(inputs);

        if (equals(outputs, expectedOutputs))
        {
            rightGuesses++;
        }
        else
        {
            iteration++;
            totalIterations++;
            mlp.BackPropagate(inputs, expectedOutputs, 0.1);
            rightGuesses = 0;

            // if number of iteration exploits a threshold
            if (iteration >= 100000ll)
            {
                iteration = 0l;
                mlp.RandomizeWeights();
            }
        }
        trainingIndex++;
        trainingIndex %= trainingInputs.size();
    }
    printf("The network has been trained in '%ld' iterations.\n", totalIterations);
}

void TEST_MLP_XOR_2_2_1()
{
    std::cout << __FUNCTION__ << "... ";
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    Activation::setThreshold(0.7);
    RandomUtils::initRandomSeed();
    std::vector<int> neuronsByLayer({2,1});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.ActivationFunction = Activation::EActivationFunctionType::Threshold;
    mlp.RandomizeWeights();
#ifdef PERSIST_WEIGHTS
    loadWeightsFromFile(weightsFilePath.c_str(), mlp);
#endif

    std::vector<std::vector<double>> trainingInputs = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::vector<double>> trainingOutputs = { {0.0}, {1.0}, {1.0}, {0.0} };
    ApplySupervisedLearning(mlp, trainingInputs, trainingOutputs);

#ifdef PERSIST_WEIGHTS
    serializeToFile(weightsFilePath.c_str(), mlp);
#endif
}

void TEST_MLP_XOR_2_3_1()
{
    std::cout << __FUNCTION__ << "... ";
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    Activation::setThreshold(0.7);
    RandomUtils::initRandomSeed();
    std::vector<int> neuronsByLayer({3,1});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.ActivationFunction = Activation::EActivationFunctionType::Threshold;
    mlp.RandomizeWeights();

#ifdef PERSIST_WEIGHTS
    loadWeightsFromFile(weightsFilePath.c_str(), mlp);
#endif

    std::vector<std::vector<double>> trainingInputs = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::vector<double>> trainingOutputs = { {0.0}, {1.0}, {1.0}, {0.0} };
    ApplySupervisedLearning(mlp, trainingInputs, trainingOutputs);

#ifdef PERSIST_WEIGHTS
    serializeToFile(weightsFilePath.c_str(), mlp);
#endif
}

void TEST_MLP_XOR_2_3_3_3_1()
{
    std::cout << __FUNCTION__ << "... ";
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    Activation::setThreshold(0.7);
    RandomUtils::initRandomSeed();
    std::vector<int> neuronsByLayer({3, 3, 3, 1});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.ActivationFunction = Activation::EActivationFunctionType::Threshold;
    mlp.RandomizeWeights();

#ifdef PERSIST_WEIGHTS
    loadWeightsFromFile(weightsFilePath.c_str(), mlp);
#endif

    std::vector<std::vector<double>> trainingInputs = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::vector<double>> trainingOutputs = { {0.0}, {1.0}, {1.0}, {0.0} };
    ApplySupervisedLearning(mlp, trainingInputs, trainingOutputs);

#ifdef PERSIST_WEIGHTS
    serializeToFile(weightsFilePath.c_str(), mlp);
#endif
}

void TEST_MLP_XOR_2_3_2()
{
    std::cout << __FUNCTION__ << "... ";
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    Activation::setThreshold(0.7);
    RandomUtils::initRandomSeed();
    std::vector<int> neuronsByLayer({3, 2});
    MultiLayerPerceptron mlp(2, neuronsByLayer);
    mlp.ActivationFunction = Activation::EActivationFunctionType::Threshold;
    mlp.RandomizeWeights();

#ifdef PERSIST_WEIGHTS
    loadWeightsFromFile(weightsFilePath.c_str(), mlp);
#endif

    std::vector<std::vector<double>> trainingInputs = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::vector<double>> trainingOutputs = {  {1.0, 0.0}, {0.0, 1.0}, {0.0, 1.0}, {1.0, 0.0} };
    ApplySupervisedLearning(mlp, trainingInputs, trainingOutputs);

#ifdef PERSIST_WEIGHTS
    serializeToFile(weightsFilePath.c_str(), mlp);
#endif
}

void TEST_MLP_number_recognition_digital_clock_0_to_9()
{
    std::cout << __FUNCTION__ << "... ";
    std::string weightsFilePath = ".\\" + std::string(__FUNCTION__);
    Activation::setThreshold(0.7);
    RandomUtils::initRandomSeed();
    std::vector<int> neuronsByLayer({10, 10});
    MultiLayerPerceptron mlp(7, neuronsByLayer);
    mlp.ActivationFunction = Activation::EActivationFunctionType::Threshold;
    mlp.RandomizeWeights();

#ifdef PERSIST_WEIGHTS
    loadWeightsFromFile(weightsFilePath.c_str(), mlp);
#endif

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
    ApplySupervisedLearning(mlp, trainingInputs, trainingOutputs);

#ifdef PERSIST_WEIGHTS
    serialization::serializeToFile(weightsFilePath.c_str(), mlp);
#endif
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
