#pragma once

#include "Layer.h"

class MultiLayerPerceptron
{
private:
    std::vector<Layer*> _layers;
    Matrix* _outputs;
    FloatFunction _outputActivationFunction;

public:
    MultiLayerPerceptron(std::vector<int> &neuronsByLayerArr);
    ~MultiLayerPerceptron();
    void feedforward(Matrix& inputs);
    /**
     * Return reference to generated outputs after applying the activation function on them.
     * @return Reference to activated outputs.
     */
    Matrix& getOutputs() const;
    void print(std::ostream& stream);
    void recover(std::istream& stream);
    void setOutputActivationFunction(FloatFunction function);
};
