#include "Layer.h"

using namespace NeuralNetwork;

Layer::Layer(size_t neurons, size_t weights)
{
    for(size_t i = 0; i < neurons; i++)
    {
        std::unique_ptr<Neuron> neuron = std::make_unique<Neuron>(weights);
        neuron->ActivationFunction = Activation::EActivationFunctionType::Sigmoid;
        neuron->RandomizeWeights();
        _neurons.push_back(std::move(neuron));
    }
}

void Layer::Serialize(std::ostream& stream) const
{
    for(const auto& _neuron : _neurons)
    {
        Neuron& neuron = *_neuron;
        neuron.Serialize(stream);
    }
}

void Layer::Deserialize(std::istream &stream)
{
    for(auto& _neuron : _neurons)
    {
        Neuron& neuron = *_neuron;
        neuron.Deserialize(stream);
    }
}

std::vector<double> Layer::Feedforward(const std::vector<double>& inputs)
{
    std::vector<double> outputs(_neurons.size());
    for(size_t n = 0; n < _neurons.size(); n++)
    {
        Neuron& neuron = *_neurons[n];
        outputs[n] = neuron.Feedforward(inputs, 0.0);
    }
    return outputs;
}

size_t Layer::GetNeuronsLength() const
{
    return _neurons.size();
}

Neuron& Layer::GetNeuron(int index) const
{
    assert(index < _neurons.size());
    Neuron& neuron = *_neurons[index];
    return neuron;
}
