#pragma once

#include <memory>
#include "../../Miscellaneous/ISerializable.h"
#include "../Common/Neuron.h"

namespace NeuralNetwork
{
    class Perceptron final : public Serialization::ISerializable
    {
    private:
        double _bias;
        std::unique_ptr<Neuron> _neuron;

    public:
        explicit Perceptron(int weights);
        Neuron* GetNeuron();
        double Feedforward(const std::vector<double>& inputs);
        void Train(const std::vector<double>& inputs, double target, double learningRate);
        void RandomizeWeights();
        void Serialize(std::ostream &stream) const override;
        void Deserialize(std::istream &stream) override;
    };
}
