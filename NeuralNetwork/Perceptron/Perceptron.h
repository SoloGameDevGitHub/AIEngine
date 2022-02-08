#pragma once

#include <memory>
#include "../../Miscellaneous/ISerializable.h"
#include "../Common/Neuron.h"

namespace NeuralNetwork
{
    class Perceptron final : public serialization::ISerializable
    {
    private:
        double _bias;
        std::unique_ptr<Neuron> _neuron;

    public:
        explicit Perceptron(int weights);
        Neuron* GetNeuron();
        double feedforward(const std::vector<double>& inputs);
        void train(const std::vector<double>& inputs, double target, double learningRate);
        void randomizeWeights();
        void Serialize(std::ostream &stream) const override;
        void Deserialize(std::istream &stream) override;
    };
}
