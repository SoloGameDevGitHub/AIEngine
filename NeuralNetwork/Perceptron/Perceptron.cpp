#include "Perceptron.h"

using namespace NeuralNetwork;

Perceptron::Perceptron(int weights) : _bias(0.0)
{
    _neuron = std::make_unique<Neuron>(weights);
}

double Perceptron::Feedforward(const std::vector<double>& inputs)
{
    double output = _neuron->Feedforward(inputs, _bias);
    return output;
}

void Perceptron::Train(const std::vector<double>& inputs, double target, double learningRate)
{
    double output = Feedforward(inputs);
    double error = (target - output);
    std::vector<double> weights = _neuron->GetWeights();
    for (int c = 0; c < weights.size(); ++c)
    {
        weights[c] += inputs[c] * error * learningRate;
    }
    _neuron->SetWeights(weights);
    _bias += error;
}

void Perceptron::Serialize(std::ostream &stream) const
{
    stream << std::hex;
    stream << _bias << std::endl;
    _neuron->Serialize(stream);
}

void Perceptron::Deserialize(std::istream &stream)
{
    stream >> _bias;
    _neuron->Deserialize(stream);
}

void Perceptron::RandomizeWeights()
{
    _neuron->RandomizeWeights();
    _bias = RandomUtils::Range(-0.1, 0.1);
}

Neuron *Perceptron::GetNeuron()
{
    return _neuron.get();
}
