#include "Neuron.h"

Neuron::~Neuron()
{
    if (_weights != nullptr) delete _weights;
    if (_outputs != nullptr) delete _outputs;
}

void Neuron::feedforward(const Matrix& inputs)
{
    if (_outputs != nullptr) delete _outputs;
    _outputs = Matrix::multiply(*_weights, inputs);
}

void Neuron::setWeights(Matrix* const weights)
{
    if (_weights == weights) return;
    if (_weights != nullptr) delete _weights;
    _weights = weights;
}

Matrix* Neuron::getOutputs() const
{
    return _outputs;
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
