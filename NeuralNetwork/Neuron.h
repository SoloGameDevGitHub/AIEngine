#pragma once

#include "../Miscellaneous/Matrix.h"
#include "../Miscellaneous/Random.h"
#include "ActivationFunctions.h"
#include "../Miscellaneous/ISerializable.h"

namespace neuralnetwork
{
    class Neuron final : public serialization::ISerializable
    {
    private:
        std::vector<double> _weights;
        activation::function _activationFunction;

    public:
        explicit Neuron(int weightsLength);
        const std::vector<double>& getWeights() const;
        double feedforward(const std::vector<double>& inputs, double bias) const;
        void setWeights(const std::vector<double>& weights);
        void serialize(std::ostream &stream) const override;
        void deserialize(std::istream &stream) override;
        void setActivationFunction(activation::function& activationFunction);
        void randomizeWeights();
    };
}
