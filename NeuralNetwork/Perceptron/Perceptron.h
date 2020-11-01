#ifndef NEURALNETWORK_PERCEPTRON_H
#define NEURALNETWORK_PERCEPTRON_H
#include "Neuron.h"
#include "../Common/ActivationFunctions.h"

class Perceptron
{
private:
    std::unique_ptr<Neuron> _neuron;
    const double _learningRate = 0.1;
    DoubleFunction _activationFunction;
    void initializeWeights(int length) const;
public:
    Perceptron(int weightsLength);
    ~Perceptron();
    void print(std::ostream& stream) const;
    void recover(std::istream& stream) const;
    void setActivationFunction(DoubleFunction activationFunction);
    double feedforward(const Matrix& inputs) const;
    void train(const Matrix& inputs, const double output);
    const Neuron& getNeuron() const;
};
#endif //NEURALNETWORK_PERCEPTRON_H
