#ifndef NEURALNETWORK_NEURON_H
#define NEURALNETWORK_NEURON_H

#include "../Common/Matrix.h"

class Neuron
{
private:
    Matrix* _weights = nullptr;
    float _bias = 0.0f;
    Matrix* _outputs;

public:
    ~Neuron();
    void feedforward(const Matrix& inputs);
    void setWeights(Matrix* const weights);
    Matrix* getWeights() const;
    Matrix* getOutputs() const;
    float getBias() const;
    void setBias(float bias);
};

#endif //NEURALNETWORK_NEURON_H
