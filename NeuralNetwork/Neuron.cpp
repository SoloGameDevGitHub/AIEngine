#include <iomanip>
#include "Neuron.h"

Neuron::Neuron(int weights)
{
    _weights = std::vector<double>(weights);
}

double Neuron::feedforward(const std::vector<double> inputs, double bias) const
{
    double output = bias;
    for (int i = 0; i < _weights.size(); ++i)
    {
        output += _weights[i] * inputs[i];
    }
    if (_activationFunction != nullptr)
    {
        output = _activationFunction(output);
    }
    return output;
}

void Neuron::randomizeWeights()
{
    for (int i = 0; i < _weights.size(); ++i)
    {
        _weights[i] = random::range(-1.0,1.0);
    }
}

void Neuron::serialize(std::ostream &stream) const
{
    stream << std::setprecision(18) << std::hex;
    for (int i = 0; i < _weights.size(); ++i)
    {
        stream << _weights[i] << std::endl;
    }
}

void Neuron::deserialize(std::istream& stream)
{
    stream >> std::setprecision(18) >> std::hex;
    for (int i = 0; i < _weights.size(); ++i)
    {
        double weight;
        stream >> weight;
        _weights[i] = weight;
    }
}

void Neuron::setActivationFunction(activationfunction::function activationFunction)
{
    _activationFunction = activationFunction;
}

std::vector<double> Neuron::getWeights() const
{
    return _weights;
}

void Neuron::setWeights(std::vector<double> weights)
{
    _weights = weights;
}
