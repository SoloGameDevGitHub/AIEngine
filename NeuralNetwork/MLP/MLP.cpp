#include "MLP.h"

MultiLayerPerceptron::MultiLayerPerceptron(std::vector<int> &neuronsByLayerArr)
{
    int layersLength = neuronsByLayerArr.size();
    int inputsLength = neuronsByLayerArr[0];
    for (int i = 0; i < layersLength; i++)
    {
        int weightsLength = neuronsByLayerArr[i];
        std::unique_ptr<Layer> layer = std::make_unique<Layer>(weightsLength, inputsLength);
        _layers.push_back(std::move(layer));
        inputsLength = weightsLength;
    }
    _rawOutputs = std::make_unique<Matrix>(inputsLength, 1);
    _outputs = std::make_unique<Matrix>(inputsLength, 1);
    _outputActivationFunction = noActivation;
}

MultiLayerPerceptron::~MultiLayerPerceptron()
{
    _outputActivationFunction = nullptr;
    _layers.clear();
}

void MultiLayerPerceptron::feedforward(Matrix& inputs) const
{
    Matrix& tempOutputs = inputs;
    for(int i = 0; i < _layers.size(); i++)
    {
        const std::unique_ptr<Layer>& layer = _layers[i];
        layer->feedforward(tempOutputs);
        tempOutputs = layer->getOutputs();
    }
    //_rawOutputs = std::make_unique<Matrix>(tempOutputs);
    Matrix::applyFunction(_outputActivationFunction, tempOutputs, *_outputs);
}

void MultiLayerPerceptron::backpropagate(const std::vector<double>& inputs,
                                         const std::vector<double>& outputs,
                                         double learningRate)  const
{
    //TODO(andrei) implement backpropagation algorithm here
}

const Layer& MultiLayerPerceptron::getLayer(int index) const
{
    assert(index < _layers.size());
    const std::unique_ptr<Layer>& layer = _layers[index];
    return *layer;
}

const Matrix& MultiLayerPerceptron::getOutputs() const
{
    return *_outputs;
}

const Matrix& MultiLayerPerceptron::getRawOutputs() const
{
    return *_rawOutputs;
}

void MultiLayerPerceptron::setOutputActivationFunction(DoubleFunction function)
{
    _outputActivationFunction = function;
}

void MultiLayerPerceptron::print(std::ostream& stream) const
{
    for(int i = 0; i < _layers.size(); i++)
    {

        const std::unique_ptr<Layer>& layer = _layers[i];
        layer->print(stream);
    }
}

void MultiLayerPerceptron::recover(std::istream& stream) const
{
    for(int i = 0; i < _layers.size(); i++)
    {
        const std::unique_ptr<Layer>& layer = _layers[i];
        layer->recover(stream);
    }
}
