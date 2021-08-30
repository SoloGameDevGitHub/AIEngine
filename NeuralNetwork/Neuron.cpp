#include <iomanip>
#include "Neuron.h"

using namespace neuralnetwork;

Neuron::Neuron(int weights)
{
    _weights = std::vector<double>(weights);
    _activationFunction = nullptr;
}

double Neuron::feedforward(const std::vector<double>& inputs, double bias) const
{
    // Sum up weights * inputs
    double output = bias;
    for (int i = 0; i < _weights.size(); ++i)
    {
        output += _weights[i] * inputs[i];
    }

    // apply the activation function (if applicable)
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
        weight = random::range(-1.0, 1.0);

        // It fixes zeroed weights.
        // if a weight is exactly zero, the network won't be able to learn.
        if (weight == 0.0)
        {
            weight = 0.000001;
        }
    }
}

void Neuron::serialize(std::ostream& stream) const
{
    // serialize in hexadecimal, so we don't lose floating point precision
    stream << std::setprecision(18) << std::hex;

    // write weights into the stream
    for (const double& weight : _weights)
    {
        stream << weight << std::endl;
    }
}

void Neuron::deserialize(std::istream& stream)
{
    // deserialize in hexadecimal, so we don't lose floating point precision
    stream >> std::setprecision(18) >> std::hex;

    // read weights from the stream
    for (double& weight : _weights)
    {
        stream >> weight;
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
