#include "Neuron.h"

Matrix* Neuron::feedforward(Matrix* const inputs)
{
    Matrix* outputs = Matrix::multiply(_weights, inputs);
    return outputs;
}

void Neuron::setWeights(Matrix* const weights)
{
    if (_weights == weights) return;
    if (_weights != nullptr) delete _weights;
    _weights = weights;
}

Matrix* Neuron::getWeights() const
{
    return _weights;
}

float Neuron::getBias() const
{
    return _bias;
}

void Neuron::setBias(float bias)
{
    _bias = bias;
}
