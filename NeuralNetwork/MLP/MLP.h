#pragma once

#include "../Common/ActivationFunctions.h"
#include "Layer.h"

namespace NeuralNetwork
{
    class MultiLayerPerceptron final : public Serialization::ISerializable
    {
    private:
        std::vector<std::unique_ptr<Layer>> _layers;
        std::vector<std::vector<double>> _inputsByLayer;

    public:
        Activation::EActivationFunctionType ActivationFunction = Activation::EActivationFunctionType::None;

        MultiLayerPerceptron(int inputsLength, const std::vector<int> &neuronsByLayerArr);
        std::vector<double> Feedforward(const std::vector<double>& inputs);
        void BackPropagate(const std::vector<double>& inputs, const std::vector<double>& targets, const double learningRate);
        void Serialize(std::ostream& stream) const override;
        void Deserialize(std::istream& stream) override;
        size_t GetLayersLength() const;
        Layer& GetLayer(size_t index) const;
        void RandomizeWeights() const;
    };
}
