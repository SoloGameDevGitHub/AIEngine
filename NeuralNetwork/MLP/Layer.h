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
        Layer(size_t neurons, size_t weights);
        std::vector<double> feedforward(const std::vector<double>& inputs);
        void Serialize(std::ostream &stream) const override;
        void Deserialize(std::istream &stream) override;
        Neuron& getNeuron(int index) const;
        size_t getNeuronsLength() const;
    };
}
