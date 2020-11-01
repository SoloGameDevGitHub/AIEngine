#include "Neuron.h"

Neuron::Neuron() { }

Neuron::Neuron(const Neuron& source) : _bias(source._bias)
{
    const Matrix& weights = *source._weights;
    _weights = std::make_unique<Matrix>(weights);
}

void Neuron::setWeights(std::unique_ptr<Matrix>& weights)
{
    _weights = std::move(weights);
}

const Matrix& Neuron::getWeights() const
{
    return *_weights;
}

double Neuron::getBias() const
{
    return _bias;
}

void Neuron::setBias(double bias)
{
    _bias = bias;
}
