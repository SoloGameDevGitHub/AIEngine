#include "MLP.h"

MultiLayerPerceptron::MultiLayerPerceptron(std::vector<int> &neuronsByLayerArr)
{
    int layersLength = neuronsByLayerArr.size();
    int previousWeightsLength = neuronsByLayerArr[0];
    for (int i = 0; i < layersLength; i++)
    {
        int weightsLength = neuronsByLayerArr[i];
        Layer* layer = new Layer(weightsLength, previousWeightsLength);
        _layers.push_back(layer);
        previousWeightsLength = weightsLength;
    }
    _outputs = new Matrix(previousWeightsLength, 1);
    _outputActivationFunction = noActivation;
}

MultiLayerPerceptron::~MultiLayerPerceptron()
{
    _outputActivationFunction = nullptr;
    if (_outputs != nullptr)
        delete _outputs;
    for (int i = 0; i < _layers.size(); ++i)
    {
        Layer* layer = _layers[i];
        if (layer != nullptr)
            delete layer;
    }
    _layers.clear();
}

void MultiLayerPerceptron::feedforward(Matrix& inputs)
{
    Matrix& tempOutputs = inputs;
    for(int i = 0; i < _layers.size(); i++)
    {
        Layer* layer = _layers[i];
        layer->feedforward(tempOutputs);
        tempOutputs = layer->getOutputs();
    }
    Matrix::applyFunction(_outputActivationFunction, tempOutputs, *_outputs);
}

Matrix& MultiLayerPerceptron::getOutputs() const
{
    return *_outputs;
}

void MultiLayerPerceptron::setOutputActivationFunction(FloatFunction function)
{
    _outputActivationFunction = function;
}

void MultiLayerPerceptron::print(std::ostream& stream)
{
    for(int i = 0; i < _layers.size(); i++)
    {
        Layer* layer = _layers[i];
        layer->print(stream);
    }
}

void MultiLayerPerceptron::recover(std::istream& stream)
{
    for(int i = 0; i < _layers.size(); i++)
    {
        Layer* layer = _layers[i];
        layer->recover(stream);
    }
}
