#include "MLP.h"

using namespace NeuralNetwork;

MultiLayerPerceptron::MultiLayerPerceptron(int inputsLength, const std::vector<int> &neuronsByLayerArr)
{
    int layersLength = neuronsByLayerArr.size();
    _inputsByLayer = std::vector<std::vector<double>>(layersLength);
    int previousLayerLength = inputsLength + 1; // insert bias neuron
    for (int l = 0; l < layersLength; l++)
    {
        _inputsByLayer[l] = std::vector<double>(previousLayerLength);
        int weightsLength = neuronsByLayerArr[l];
        if (l < (layersLength - 1))
        {
            weightsLength++; // insert bias neuron
        }
        std::unique_ptr<Layer> layer = std::make_unique<Layer>(weightsLength, previousLayerLength);
        _layers.push_back(std::move(layer));
        previousLayerLength = weightsLength;
    }
}

std::vector<double> MultiLayerPerceptron::Feedforward(const std::vector<double>& inputs)
{
    std::vector<double> outputs(inputs);
    for (int l = 0; l < _layers.size(); l++)
    {
        const std::unique_ptr<Layer> &layer = _layers[l];
        outputs.emplace_back(1.0); // insert bias
        _inputsByLayer[l] = outputs;
        outputs = layer->feedforward(outputs);
    }

    // apply activation function
    Activation::Apply(ActivationFunction, outputs);

    return outputs;
}

void GetPreviousLayerErrors(const Neuron& neuron, double error, std::vector<double>& previousLayerErrors)
{
    const std::vector<double>& weights = neuron.getWeights();
    previousLayerErrors.resize(weights.size());

    double weightsSum = 0.0;
    for (double weight : weights)
    {
        weightsSum += weight;
    }

    for (int w = 0; w < weights.size(); ++w)
    {
        double percentage = weights[w] / weightsSum;
        previousLayerErrors[w] += (error * percentage);
    }
}

void UpdateNeuronWeights(Neuron &neuron, const std::vector<double> &inputs, const double output, const double error, const double learningRate)
{
    auto& weights = const_cast<std::vector<double>&>(neuron.getWeights());
    for (size_t w = 0; w < weights.size(); ++w)
    {
        double weightDifference = -(error * (output * (1.0 - output)) * inputs[w]);
        weightDifference = -(learningRate * weightDifference);
        weights[w] += weightDifference;
    }
}

void MultiLayerPerceptron::BackPropagate(const std::vector<double>& inputs, const std::vector<double>& targets, const double learningRate)
{
    std::vector<double> outputs = Feedforward(inputs);
    std::vector<double> errors(outputs.size());
    for (int o = 0; o < outputs.size(); ++o)
    {
        errors[o] = targets[o] - outputs[o];
    }
    // BackPropagate errors
    for (int l = (_layers.size() - 1); l >= 0; --l)
    {
        // reset previous layer errors
        size_t size = inputs.size();
        if (l > 0)
        {
            const std::unique_ptr<Layer> &layer = _layers[l - 1];
            size = layer->getNeuronsLength();
        }
        std::vector<double> previousLayerErrors(size);

        //BackPropagate errors
        Layer &layer = GetLayer(l);
        std::vector<double> layerInputs = _inputsByLayer[l];
        std::vector<double> layerOutputs = layer.feedforward(layerInputs);
        for (int n = 0; n < layer.getNeuronsLength(); ++n)
        {
            Neuron &neuron = layer.getNeuron(n);
            GetPreviousLayerErrors(neuron, errors[n], previousLayerErrors);
            UpdateNeuronWeights(neuron, layerInputs, layerOutputs[n], errors[n], learningRate);
        }
        errors = previousLayerErrors;
    }
}

size_t MultiLayerPerceptron::GetLayersLength() const
{
    return _layers.size();
}

Layer &MultiLayerPerceptron::GetLayer(const size_t index) const
{
    assert(index < _layers.size());
    const std::unique_ptr<Layer> &layer = _layers[index];
    return *layer;
}

void MultiLayerPerceptron::Serialize(std::ostream &stream) const
{
    for (const auto& layer : _layers)
    {
        layer->Serialize(stream);
    }
}

void MultiLayerPerceptron::Deserialize(std::istream &stream)
{
    for (auto& layer : _layers)
    {
        layer->Deserialize(stream);
    }
}

void MultiLayerPerceptron::RandomizeWeights() const
{
    for (int l = 0; l < GetLayersLength(); ++l)
    {
        Layer &layer = GetLayer(l);
        for (int n = 0; n < layer.getNeuronsLength(); ++n)
        {
            Neuron &neuron = layer.getNeuron(n);
            neuron.randomizeWeights();
        }
    }
}
