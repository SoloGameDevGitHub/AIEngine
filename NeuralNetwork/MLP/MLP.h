#pragma once

#include "../ActivationFunctions.h"
#include "Layer.h"

namespace neuralnetwork
{
    class MultiLayerPerceptron final : public serialization::ISerializable
    {
    private:
        std::vector<std::unique_ptr<Layer>> _layers;
        std::vector<std::vector<double>> _inputsByLayer;
        activation::vector_function _outputActivationFunction;

    public:
        MultiLayerPerceptron(int inputsLength, const std::vector<int> &neuronsByLayerArr);
        std::vector<double> feedforward(const std::vector<double> inputs);
        void backpropagate(const std::vector<double> inputs, const std::vector<double> targets, const double learningRate);
        void serialize(std::ostream &stream) const override;
        void deserialize(std::istream &stream) override;
        void setActivationFunction(activation::vector_function activationFunction);
        int getLayersLength() const;
        Layer& getLayer(int index) const;
        void randomizeWeights(MultiLayerPerceptron &mlp) const;
    };
}
