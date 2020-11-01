#include "Perceptron.h"
#include "../Common/Random.h"

Perceptron::Perceptron(int weightsLength)
{
    _neuron = std::make_unique<Neuron>();
    initializeWeights(weightsLength);
    setActivationFunction(noActivation);
}

void Perceptron::initializeWeights(int length) const
{
    std::unique_ptr<Matrix> weights = std::make_unique<Matrix>(1, length);
    for (int c = 0; c < weights->getColumns(); ++c)
    {
        double randomValue = random::range(-1.0, 1.0);
        weights->set(0,c,randomValue);
    }
    _neuron->setWeights(weights);

    double randomBias = random::range(-0.1,0.1);
    _neuron->setBias(randomBias);
}

Perceptron::~Perceptron()
{
    _activationFunction = nullptr;
}

void Perceptron::setActivationFunction(DoubleFunction activationFunction)
{
    _activationFunction = activationFunction;
}

const Neuron& Perceptron::getNeuron() const
{
    const Neuron& neuron = *_neuron;
    return neuron;
}

void Perceptron::print(std::ostream& stream) const
{
    const Matrix& weights = _neuron->getWeights();
    stream << weights.getRows() << " ";
    stream << weights.getColumns() << std::endl;
    stream << _neuron->getBias() << std::endl;
    for (int c = 0; c < weights.getColumns(); ++c)
    {
        const double weight = weights.get(0, c);
        stream << weight << std::endl;
    }
}

void Perceptron::recover(std::istream& stream) const
{
    int rows, columns;
    stream >> rows;
    stream >> columns;

    double bias;
    stream >> bias;
    _neuron->setBias(bias);

    const Matrix& matrix = _neuron->getWeights();
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < columns; ++c)
        {
            double weight;
            stream >> weight;
            const_cast<Matrix&>(matrix).set(r, c, weight);
        }
    }
}

void Perceptron::train(const Matrix& inputs, const double target)
{
    double output = feedforward(inputs);
    double error = (target - output);
    std::unique_ptr<Matrix> weights = std::make_unique<Matrix>(_neuron->getWeights());
    for (int c = 0; c < weights->getColumns(); ++c)
    {
        double value = inputs.get(c, 0) * error * _learningRate;
        weights->set(0, c, value);
    }
    _neuron->setWeights(weights);
    double bias = _neuron->getBias();
    bias += error;
    _neuron->setBias(bias);
}

double Perceptron::feedforward(const Matrix& inputs) const
{
    const Matrix& weights = _neuron->getWeights();
    std::unique_ptr<Matrix> outputs = Matrix::multiply(weights, inputs);
    double sum =  _neuron->getBias();
    for (int r = 0; r < outputs->getRows(); ++r)
    {
        sum += outputs->get(r,0);
    }
    sum = _activationFunction(sum);
    return sum;
}
