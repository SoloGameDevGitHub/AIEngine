#include "Neuron.h"

Neuron::Neuron()
{
    //
}

Neuron::Neuron(const Neuron& source) : _weights(std::make_unique<Matrix>(*source._weights)),
                                       _bias(source._bias)
{
    //
}

std::shared_ptr<Matrix> Neuron::feedforward(const Matrix &inputs)
{
    auto outputs = Matrix::multiply(*_weights, inputs);
    return outputs;
}

void Neuron::setWeights(const Matrix &weights)
{
    Matrix* newWeights = new Matrix(weights);
    _weights.reset(newWeights);
}

Matrix& Neuron::getWeights()
{
    return *_weights;
}

float Neuron::getBias() const
{
    return _bias;
}

void Neuron::setBias(float bias)
{
    _bias = bias;
}
