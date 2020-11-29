#include "MLP.h"

using namespace neuralnetwork;

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

std::vector<double> MultiLayerPerceptron::feedforward(const std::vector<double> inputs)
{
    std::vector<double> outputs(inputs);
    for (int l = 0; l < _layers.size(); l++)
    {
        const std::unique_ptr<Layer> &layer = _layers[l];
        outputs.emplace_back(1.0); // insert bias
        _inputsByLayer[l] = outputs;
        outputs = layer->feedforward(outputs);
    }
    if (_outputActivationFunction != nullptr)
    {
        _outputActivationFunction(outputs);
    }
    return outputs;
}

void getPreviousLayerErrors(const Neuron &neuron, double error, std::vector<double> &previousLayerErrors)
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
        previousLayerErrors[w] += (error * percentage);
    }
}

void updateNeuronWeights(Neuron &neuron, const std::vector<double> &inputs, const double output, const double error, const double learningRate)
{
    std::vector<double> weights = neuron.getWeights();
    for (int w = 0; w < weights.size(); ++w)
    {
        double weightDifference = -(error * (output * (1.0 - output)) * inputs[w]);
        weightDifference = -(learningRate * weightDifference);
        weights[w] += weightDifference;
    }
    neuron.setWeights(weights);
}

void MultiLayerPerceptron::backpropagate(const std::vector<double> inputs, const std::vector<double> targets, const double learningRate)
{
    std::vector<double> outputs = feedforward(inputs);
    std::vector<double> errors(outputs.size());
    for (int o = 0; o < outputs.size(); ++o)
    {
        errors[o] = targets[o] - outputs[o];
    }
    // backpropagate errors
    for (int l = (_layers.size() - 1); l >= 0; --l)
    {
        // reset previous layer errors
        int size = inputs.size();
        if (l > 0)
        {
            const std::unique_ptr<Layer> &layer = _layers[l - 1];
            size = layer->getNeuronsLength();
        }
        std::vector<double> previousLayerErrors(size);

        //backpropagate errors
        Layer &layer = getLayer(l);
        std::vector<double> layerInputs = _inputsByLayer[l];
        std::vector<double> layerOutputs = layer.feedforward(layerInputs);
        for (int n = 0; n < layer.getNeuronsLength(); ++n)
        {
            Neuron &neuron = layer.getNeuron(n);
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

Layer &MultiLayerPerceptron::getLayer(int index) const
{
    assert(index < _layers.size());
    const std::unique_ptr<Layer> &layer = _layers[index];
    return *layer;
}

void MultiLayerPerceptron::serialize(std::ostream &stream) const
{
    for (int i = 0; i < _layers.size(); i++)
    {
        const std::unique_ptr<Layer> &layer = _layers[i];
        layer->serialize(stream);
    }
}

void MultiLayerPerceptron::deserialize(std::istream &stream)
{
    for (int i = 0; i < _layers.size(); i++)
    {
        const std::unique_ptr<Layer> &layer = _layers[i];
        layer->deserialize(stream);
    }
}

void MultiLayerPerceptron::setActivationFunction(activation::vector_function activationFunction)
{
    _outputActivationFunction = activationFunction;
}

void MultiLayerPerceptron::randomizeWeights(MultiLayerPerceptron &mlp) const
{
    for (int l = 0; l < mlp.getLayersLength(); ++l)
    {
        Layer &layer = mlp.getLayer(l);
        for (int n = 0; n < layer.getNeuronsLength(); ++n)
        {
            Neuron &neuron = layer.getNeuron(n);
            neuron.randomizeWeights();
        }
    }
}
