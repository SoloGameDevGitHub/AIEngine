#pragma once

#include "../Miscellaneous/Matrix.h"
#include "../Miscellaneous/Random.h"
#include "ActivationFunctions.h"
#include "../Miscellaneous/ISerializable.h"

class Neuron final : public ISerializable
{
private:
    std::vector<double> _weights;
    activationfunction::function _activationFunction;

public:
    Neuron(int weightsLength);
    std::vector<double> getWeights() const;
    double feedforward(const std::vector<double> inputs, double bias) const;
    void setWeights(std::vector<double> weights);
    void serialize(std::ostream &stream) const override;
    void deserialize(std::istream &stream) override;
    void setActivationFunction(activationfunction::function activationFunction);
    void randomizeWeights();
};
