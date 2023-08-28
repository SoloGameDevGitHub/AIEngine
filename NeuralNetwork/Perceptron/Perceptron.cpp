#include "Perceptron.h"

using namespace NeuralNetwork;

Perceptron::Perceptron(int weights) : _bias(0.0)
{
    _neuron = std::make_unique<Neuron>(weights);
}

double Perceptron::feedforward(const std::vector<double>& inputs)
{
    double output = _neuron->feedforward(inputs, _bias);
    return output;
}

void Perceptron::train(const std::vector<double>& inputs, double target, double learningRate)
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

void Perceptron::Serialize(std::ostream &stream) const
{
    stream << std::hex;
    stream << _bias << std::endl;
    _neuron->Serialize(stream);
}

void Perceptron::Deserialize(std::istream &stream)
{
    stream >> _bias;
    _neuron->Deserialize(stream);
}

void Perceptron::randomizeWeights()
{
    _neuron->randomizeWeights();
    _bias = RandomUtils::Range(-0.1, 0.1);
}

Neuron *Perceptron::GetNeuron()
{
    return _neuron.get();
}
