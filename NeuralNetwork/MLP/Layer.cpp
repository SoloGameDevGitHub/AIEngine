#include "Layer.h"

Layer::Layer(int perceptronsLength,
             int inputsLength) : _inputsLength(inputsLength)
{
    for(int i = 0; i < perceptronsLength; i++)
    {

        std::unique_ptr<Perceptron> perceptron = std::make_unique<Perceptron>(inputsLength);
        perceptron->setActivationFunction(sigmoid);
        _perceptrons.push_back(std::move(perceptron));
    }
    _outputs = std::make_unique<Matrix>(perceptronsLength, 1);
}



Layer::~Layer()
{
    _perceptrons.clear();
}

void Layer::print(std::ostream& stream) const
{
    for(unsigned int i = 0; i < _perceptrons.size(); i++)
    {
        const Perceptron& perceptron = *_perceptrons[i];
        perceptron.print(stream);
    }
}

void Layer::recover(std::istream& stream) const
{
    for(unsigned int i = 0; i < _perceptrons.size(); i++)
    {
        const Perceptron& perceptron = *_perceptrons[i];
        perceptron.recover(stream);
    }
}

void Layer::feedforward(const Matrix& inputs)
{
    assert(_inputsLength == inputs.getRows());
    for(unsigned int i = 0; i < _perceptrons.size(); i++)
    {
        const Perceptron& perceptron = *_perceptrons[i];
        double value = perceptron.feedforward(inputs);
        _outputs->set(i, 0, value);
    }
}

const Perceptron& Layer::getPerceptron(int index) const
{
    assert(index < _perceptrons.size());
    const Perceptron& perceptron = *_perceptrons[index];
    return perceptron;
}

const Matrix& Layer::getOutputs() const
{
    const Matrix& matrix = *_outputs;
    return matrix;
}
