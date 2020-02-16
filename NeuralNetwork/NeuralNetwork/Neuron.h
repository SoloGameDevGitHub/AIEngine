#ifndef NEURALNETWORK_NEURON_H
#define NEURALNETWORK_NEURON_H

#include "Matrix.h"

class Neuron
{
private:
    Matrix* _weights = nullptr;
    float _bias = 0.0f;

public:
    ~Neuron();
    Matrix* feedforward(Matrix* const inputs);
    void setWeights(Matrix* const weights);
    Matrix* getWeights() const;
    float getBias() const;
    void setBias(float bias);
};

#endif //NEURALNETWORK_NEURON_H
