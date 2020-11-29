#pragma once

#include "../ActivationFunctions.h"
#include "Layer.h"

class MultiLayerPerceptron : public ISerializable
{
private:
    std::vector<std::unique_ptr<Layer>> _layers;
    std::vector<std::vector<double>> _inputsByLayer;
    activationfunction::function _outputActivationFunction;

public:
    MultiLayerPerceptron(int inputsLength, const std::vector<int>& neuronsByLayerArr);
    std::vector<double> feedforward(std::vector<double> inputs);
    void backpropagate(std::vector<double> inputs, std::vector<double> targets, const double learningRate);
    void serialize(std::ostream &stream) const override;
    void deserialize(std::istream &stream) override;
    void setOutputActivationFunction(activationfunction::function activationFunction);
    int getLayersLength() const;
    Layer& getLayer(int index) const;
};
