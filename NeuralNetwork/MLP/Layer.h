#pragma once

#include <memory>
#include "../../Miscellaneous/ISerializable.h"
#include "../ActivationFunctions.h"
#include "../Neuron.h"

class Layer : public ISerializable
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
