#include "Perceptron.h"
#include "../../Common/Random.h"

Perceptron::Perceptron(int weightsLength)
{
    _neuron = std::make_unique<Neuron>();
    auto weights = std::make_unique<Matrix>(1, weightsLength);
    for (int c = 0; c < weights->getColumns(); ++c)
    {
        float randomValue = random::range(-1.0f, 1.0f);
        weights->set(0,c,randomValue);
    }
    _neuron->setWeights(*weights);
    float randomBias = random::range(-0.1f,0.1f);
    _neuron->setBias(randomBias);
    _activationFunction = noActivation;
}

Perceptron::Perceptron(const Perceptron &source)
{
    Neuron& neuron = *source._neuron;
    _neuron = std::make_unique<Neuron>(neuron);
    _activationFunction = source._activationFunction;
}

Perceptron::~Perceptron()
{
    _activationFunction = nullptr;
}

void Perceptron::setActivationFunction(FloatFunction activationFunction)
{
    _activationFunction = activationFunction;
}

Neuron& Perceptron::getNeuron()
{
    return *_neuron;
}

void Perceptron::print(std::ostream& stream)
{
    const Matrix& weights = _neuron->getWeights();
    stream << weights.getRows() << " ";
    stream << weights.getColumns() << std::endl;
    stream << _neuron->getBias() << std::endl;
    for (int c = 0; c < weights.getColumns(); ++c)
    {
        float weight = weights.get(0, c);
        stream << weight << std::endl;
    }
}

void Perceptron::recover(std::istream& stream)
{
    int rows, columns;
    stream >> rows;
    stream >> columns;

    float bias;
    stream >> bias;
    _neuron->setBias(bias);

    Matrix& matrix = _neuron->getWeights();
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < columns; ++c)
        {
            float weight;
            stream >> weight;
            matrix.set(r, c, weight);
        }
    }
}

void Perceptron::train(const Matrix& inputs, const float target)
{
    float output = feedforward(inputs);
    float error = (target - output);
    Matrix& weights = _neuron->getWeights();
    for (int c = 0; c < weights.getColumns(); ++c)
    {
        float value = inputs.get(c, 0) * error * _learningRate;
        weights.set(0, c, value);
    }
    float bias = _neuron->getBias();
    bias += error;
    _neuron->setBias(bias);
}

float Perceptron::feedforward(const Matrix& inputs)
{
    auto outputs = _neuron->feedforward(inputs);
    float sum =  _neuron->getBias();
    for (int r = 0; r < outputs->getRows(); ++r)
    {
        sum += outputs->get(r,0);
    }
    sum = _activationFunction(sum);
    return sum;
}
