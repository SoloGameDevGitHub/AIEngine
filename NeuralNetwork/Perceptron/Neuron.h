#ifndef NEURALNETWORK_NEURON_H
#define NEURALNETWORK_NEURON_H

#include "../../Common/Matrix.h"

class Neuron
{
private:
    std::unique_ptr<Matrix> _weights;
    float _bias = 0.0f;

public:
    Neuron();
    Neuron(const Neuron& source);
    std::unique_ptr<Matrix> feedforward(const Matrix &inputs);
    void setWeights(const Matrix &weights);
    Matrix& getWeights();
    float getBias() const;
    void setBias(float bias);
};

#endif //NEURALNETWORK_NEURON_H
