#include "Perceptron.h"

#define SIGN(X) X >= 0.0 ? 1 : -1

Perceptron::~Perceptron()
{
    if (_neuron == nullptr)
        delete _neuron;
}

Perceptron::Perceptron(int weightsLength)
{
    _neuron = new Neuron();
    Matrix* weights = new Matrix(1, weightsLength);
    for (int c = 0; c < weights->getColumns(); ++c)
    {
        float randomValue = (float(rand())/float((RAND_MAX)) * 2.0) - 1.0; //value in range -1.0/1.0
        weights->set(0,c,randomValue);
    }
    _neuron->setWeights(weights);
    float randomBias = (float(rand())/float((RAND_MAX)) * 0.2) - 0.1; //value in range -0.1/0.1
    _neuron->setBias(randomBias);
}

void Perceptron::train(Matrix* const inputs, const float target)
{
    float output = feedforward(inputs);
    float error = (target - output);
    Matrix* weights = _neuron->getWeights();
    for (int c = 0; c < weights->getColumns(); ++c)
    {
        float value = inputs->get(c, 0) * error * _learningRate;
        weights->set(0, c, value);
    }
    float bias = _neuron->getBias();
    bias += error;
    _neuron->setBias(bias);
}

float Perceptron::feedforward(Matrix* const inputs)
{
    assert(_neuron->getWeights()->getColumns() == inputs->getRows());
    Matrix* outputs = _neuron->feedforward(inputs);
    float sum =  _neuron->getBias();
    for (int r = 0; r < outputs->getRows(); ++r)
    {
        sum += outputs->get(r,0);
    }
    delete outputs;
    return SIGN(sum);
}
