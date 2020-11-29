#include "Layer.h"

using namespace neuralnetwork;

Layer::Layer(int neurons, int weights)
{
    for(int i = 0; i < neurons; i++)
    {
        std::unique_ptr<Neuron> neuron = std::make_unique<Neuron>(weights);
        neuron->setActivationFunction(activation::sigmoid);
        neuron->randomizeWeights();
        _neurons.push_back(std::move(neuron));
    }
}

void Layer::serialize(std::ostream& stream) const
{
    for(unsigned int i = 0; i < _neurons.size(); i++)
    {
        Neuron& neuron = *_neurons[i];
        neuron.serialize(stream);
    }
}

void Layer::deserialize(std::istream &stream)
{
    for(unsigned int i = 0; i < _neurons.size(); i++)
    {
        Neuron& neuron = *_neurons[i];
        neuron.deserialize(stream);
    }
}

std::vector<double> Layer::feedforward(const std::vector<double>& inputs)
{
    std::vector<double> outputs(_neurons.size());
    for(unsigned int i = 0; i < _neurons.size(); i++)
    {
        Neuron& neuron = *_neurons[i];
        outputs[i] = neuron.feedforward(inputs, 0.0);
    }
    return outputs;
}

int Layer::getNeuronsLength() const
{
    return _neurons.size();
}

Neuron& Layer::getNeuron(int index) const
{
    assert(index < _neurons.size());
    Neuron& neuron = *_neurons[index];
    return neuron;
}
