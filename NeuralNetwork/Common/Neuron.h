#pragma once

#include "../../Miscellaneous/Matrix.h"
#include "../../Miscellaneous/Random.h"
#include "../../Miscellaneous/ISerializable.h"
#include "ActivationFunctions.h"

namespace NeuralNetwork
{
    class Neuron final : public serialization::ISerializable
    {
    private:
        std::vector<double> _weights;

    public:
        Activation::EActivationFunctionType ActivationFunction = Activation::EActivationFunctionType::None;

        explicit Neuron(int weightsLength);
        void randomizeWeights();

        double feedforward(const std::vector<double>& inputs, double bias) const;
        void setWeights(const std::vector<double>& weights);
        const std::vector<double>& getWeights() const;

        // serialization
        void Serialize(std::ostream &stream) const override;
        void Deserialize(std::istream &stream) override;
    };
}
