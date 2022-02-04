#pragma once

#include <memory>
#include "../../Miscellaneous/ISerializable.h"
#include "../Common/ActivationFunctions.h"
#include "../Common/Neuron.h"

namespace NeuralNetwork
{
    class Layer final : public serialization::ISerializable
    {
    private:
        std::vector<std::unique_ptr<Neuron>> _neurons;

    public:
        Layer(int neurons, int weights);
        std::vector<double> feedforward(const std::vector<double>& inputs);
        void serialize(std::ostream &stream) const override;
        void deserialize(std::istream &stream) override;
        Neuron& getNeuron(int index) const;
        int getNeuronsLength() const;
    };
}
