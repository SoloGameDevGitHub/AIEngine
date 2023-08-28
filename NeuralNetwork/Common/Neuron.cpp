#include "Neuron.h"

#include <iomanip>

using namespace NeuralNetwork;

Neuron::Neuron(int weights)
{
    _weights = std::vector<double>(weights);
}

double Neuron::Feedforward(const std::vector<double>& inputs, double bias) const
{
    // calculate Neuron's output
    double output = bias;
    for (int i = 0; i < _weights.size(); ++i)
    {
        output += _weights[i] * inputs[i];
    }

    // apply the Activation function (if existing)
    Activation::Apply(ActivationFunction, output);

    return output;
}

void Neuron::RandomizeWeights()
{
    for (double& weight : _weights)
    {
        weight = RandomUtils::Range(-1.0, 1.0);

        // fix absolute zero weights
        if (weight == 0.0)
        {
            weight = 0.000001;
        }
    }
}

void Neuron::Serialize(std::ostream &stream) const
{
    stream << std::setprecision(18) << std::hex;
    for (const double& _weight : _weights)
    {
        stream << _weight << std::endl;
    }
}

void Neuron::Deserialize(std::istream& stream)
{
    stream >> std::setprecision(18) >> std::hex;
    for (double& _weight : _weights)
    {
        stream >> _weight;
    }
}

const std::vector<double>& Neuron::GetWeights() const
{
    return _weights;
}

void Neuron::SetWeights(const std::vector<double>& weights)
{
    _weights = weights;
}
