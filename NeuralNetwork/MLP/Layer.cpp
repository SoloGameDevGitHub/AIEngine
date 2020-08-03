#include "Layer.h"

Layer::Layer(int perceptronsLength,
             int inputsLength) : _inputsLength(inputsLength)
{
    for(int i = 0; i < perceptronsLength; i++)
    {
        Perceptron* perceptron = new Perceptron(inputsLength);
        perceptron->setActivationFunction(sigmoid);
        _perceptrons.push_back(perceptron);
    }
    _outputs = std::make_unique<Matrix>(perceptronsLength, 1);
}

Layer::~Layer()
{
    for (int i = 0; i < _perceptrons.size(); ++i)
    {
        Perceptron* perceptron = _perceptrons[i];
        delete perceptron;
    }
    _perceptrons.clear();
}

void Layer::print(std::ostream& stream)
{
    for(int i = 0; i < _perceptrons.size(); i++)
    {
        Perceptron* perceptron = _perceptrons[i];
        perceptron->print(stream);
    }
}

void Layer::recover(std::istream& stream)
{
    for(int i = 0; i < _perceptrons.size(); i++)
    {
        Perceptron* perceptron = _perceptrons[i];
        perceptron->recover(stream);
    }
}

void Layer::feedforward(const Matrix& inputs)
{
    assert(_inputsLength == inputs.getRows());
    for(int i = 0; i < _perceptrons.size(); i++)
    {
        Perceptron* perceptron = _perceptrons[i];
        float value = perceptron->feedforward(inputs);
        _outputs->set(i, 0, value);
    }
}

Matrix& Layer::getOutputs() const
{
    Matrix* ptr = _outputs.get();
    return *ptr;
}
