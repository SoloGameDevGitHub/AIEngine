#include "Perceptron.h"

using namespace neuralnetwork;

Perceptron::Perceptron(int weights)
{
    _neuron = std::make_unique<Neuron>(weights);
}

double Perceptron::feedforward(const std::vector<double> inputs)
{
    double output = _neuron->feedforward(inputs, _bias);
    return output;
}

void Perceptron::train(const std::vector<double> inputs, double target, double learningRate)
{
    double output = feedforward(inputs);
    double error = (target - output);
    std::vector<double> weights = _neuron->getWeights();
    for (int c = 0; c < weights.size(); ++c)
    {
        weights[c] += inputs[c] * error * learningRate;
    }
    _neuron->setWeights(weights);
    _bias += error;
}

void Perceptron::serialize(std::ostream &stream) const
{
    stream << std::hex;
    stream << _bias << std::endl;
    _neuron->serialize(stream);
}

void Perceptron::deserialize(std::istream &stream)
{
    stream >> _bias;
    _neuron->deserialize(stream);
}

void Perceptron::setActivationFunction(activation::function activationFunction)
{
    _neuron->setActivationFunction(activationFunction);
}

void Perceptron::randomizeWeights()
{
    _neuron->randomizeWeights();
    _bias = random::range(-0.1,0.1);
}
