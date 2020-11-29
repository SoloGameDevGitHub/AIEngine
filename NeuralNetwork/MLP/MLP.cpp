#include "MLP.h"

MultiLayerPerceptron::MultiLayerPerceptron(int inputsLength, const std::vector<int>& neuronsByLayerArr)
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

std::vector<double> MultiLayerPerceptron::feedforward(std::vector<double> inputs)
{
    for(int l = 0; l < _layers.size(); l++)
    {
        const std::unique_ptr<Layer>& layer = _layers[l];
        inputs.emplace_back(1.0); // insert bias
        _inputsByLayer[l] = inputs;
        inputs = layer->feedforward(inputs);
    }

    if (_outputActivationFunction != nullptr)
    {
        for (int i = 0; i < inputs.size(); ++i)
        {
            inputs[i] = _outputActivationFunction(inputs[i]);
        }
    }
    return inputs;
}

void getPreviousLayerErrors(Neuron& neuron, double neuronError, std::vector<double>& previousLayerErrors)
{
    const std::vector<double> weights = neuron.getWeights();
    if (previousLayerErrors.size() != weights.size())
    {
        previousLayerErrors = std::vector<double>(weights.size());
    }
    double weightsSum = 0.0;
    for (int w = 0; w < weights.size(); ++w)
    {
        weightsSum += weights[w];
    }
    for (int w = 0; w < weights.size(); ++w)
    {
        double percentage = weights[w] / weightsSum;
        previousLayerErrors[w] += (neuronError * percentage);
    }
}

void updateNeuronWeights(Neuron& neuron, std::vector<double> inputs, double output, double error, const double learningRate)
{
    std::vector<double> weights = neuron.getWeights();
    for (int w = 0; w < weights.size(); ++w)
    {
        double weightDifference = - (error * (output * (1.0 - output)) * inputs[w]);
        weightDifference = - (learningRate * weightDifference);
        weights[w] += weightDifference;
    }
    neuron.setWeights(weights);
}

void MultiLayerPerceptron::backpropagate(std::vector<double> inputs, std::vector<double> targets, const double learningRate)
{
    std::vector<double> outputs = feedforward(inputs);
    std::vector<double> errors(outputs.size());
    for (int o = 0; o < outputs.size(); ++o)
    {
        errors[o] = (targets[o] - outputs[o]);
    }
    // backpropagate errors
    std::vector<double> previousLayerErrors;
    for (int l = (_layers.size() - 1); l >= 0; --l)
    {
        // reset previous layer errors
        if (l == 0)
        {
            previousLayerErrors = std::vector<double>(inputs.size());
        }
        else
        {
            previousLayerErrors = std::vector<double>(_layers[(l - 1)]->getNeuronsLength());
        }
        //backpropagate errors
        Layer& layer = getLayer(l);
        std::vector<double> layerInputs = _inputsByLayer[l];
        std::vector<double> layerOutputs = layer.feedforward(layerInputs);
        for (int n = 0; n < layer.getNeuronsLength(); ++n)
        {
            Neuron& neuron = layer.getNeuron(n);
            getPreviousLayerErrors(neuron, errors[n], previousLayerErrors);
            updateNeuronWeights(neuron, layerInputs, layerOutputs[n], errors[n], learningRate);
        }
        errors = previousLayerErrors;
    }
}

int MultiLayerPerceptron::getLayersLength() const
{
    return _layers.size();
}

Layer& MultiLayerPerceptron::getLayer(int index) const
{
    assert(index < _layers.size());
    const std::unique_ptr<Layer>& layer = _layers[index];
    return *layer;
}

void MultiLayerPerceptron::serialize(std::ostream& stream) const
{
    for(int i = 0; i < _layers.size(); i++)
    {
        const std::unique_ptr<Layer>& layer = _layers[i];
        layer->serialize(stream);
    }
}

void MultiLayerPerceptron::deserialize(std::istream& stream)
{
    for(int i = 0; i < _layers.size(); i++)
    {
        const std::unique_ptr<Layer>& layer = _layers[i];
        layer->deserialize(stream);
    }
}

void MultiLayerPerceptron::setOutputActivationFunction(activationfunction::function activationFunction)
{
    _outputActivationFunction = activationFunction;
}
