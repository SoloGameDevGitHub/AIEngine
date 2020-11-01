#ifndef NEURALNETWORK_NEURON_H
#define NEURALNETWORK_NEURON_H

#include "../Common/Matrix.h"

class Neuron
{
private:
    std::unique_ptr<Matrix> _weights;
    double _bias = 0.0f;

public:
    Neuron();
    Neuron(const Neuron& source);
    const Matrix& getWeights() const;
    void setWeights(std::unique_ptr<Matrix>& weights);
    double getBias() const;
    void setBias(double bias);
};

#endif //NEURALNETWORK_NEURON_H
