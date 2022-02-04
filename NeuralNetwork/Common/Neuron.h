#pragma once

#include "../../Miscellaneous/Matrix.h"
#include "../../Miscellaneous/Random.h"
#include "ActivationFunctions.h"
#include "../../Miscellaneous/ISerializable.h"

namespace NeuralNetwork
{
    class Neuron final : public serialization::ISerializable
    {
    private:
        std::vector<double> _weights;
        activation::function _activationFunction;

    public:
        explicit Neuron(int weightsLength);
        void randomizeWeights();

        double feedforward(const std::vector<double>& inputs, double bias) const;
        void setActivationFunction(activation::function activationFunction);
        void setWeights(const std::vector<double>& weights);
        const std::vector<double>& getWeights() const;

        // serialization
        void serialize(std::ostream &stream) const override;
        void deserialize(std::istream &stream) override;
    };
}
