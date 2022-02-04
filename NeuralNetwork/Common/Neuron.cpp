#include <iomanip>
#include "Neuron.h"

using namespace NeuralNetwork;

Neuron::Neuron(int weights) : _activationFunction(nullptr)
{
    _weights = std::vector<double>(weights);
}

double Neuron::feedforward(const std::vector<double>& inputs, double bias) const
{
    // calculate Neuron's output
    double output = bias;
    for (int i = 0; i < _weights.size(); ++i)
    {
        output += _weights[i] * inputs[i];
    }

    // apply the activation function (if existing)
    if (_activationFunction != nullptr)
    {
        output = _activationFunction(output);
    }

    return output;
}

void Neuron::randomizeWeights()
{
    for (double& weight : _weights)
    {
        weight = RandomUtils::range(-1.0, 1.0);

        // fix absolute zero weights
        if (weight == 0.0)
        {
            weight = 0.000001;
        }
    }
}

void Neuron::serialize(std::ostream &stream) const
{
    stream << std::setprecision(18) << std::hex;
    for (const double& _weight : _weights)
    {
        stream << _weight << std::endl;
    }
}

void Neuron::deserialize(std::istream& stream)
{
    stream >> std::setprecision(18) >> std::hex;
    for (double& _weight : _weights)
    {
        stream >> _weight;
    }
}

void Neuron::setActivationFunction(activation::function activationFunction)
{
    _activationFunction = activationFunction;
}

const std::vector<double>& Neuron::getWeights() const
{
    return _weights;
}

void Neuron::setWeights(const std::vector<double>& weights)
{
    _weights = weights;
}
