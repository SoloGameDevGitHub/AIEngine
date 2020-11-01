#ifndef AIENGINE_MLP_H
#define AIENGINE_MLP_H
#include "Layer.h"

class MultiLayerPerceptron
{
private:
    std::vector<std::unique_ptr<Layer>> _layers;
    std::unique_ptr<Matrix> _rawOutputs;
    std::unique_ptr<Matrix> _outputs;
    DoubleFunction _outputActivationFunction;

public:
    MultiLayerPerceptron(std::vector<int> &neuronsByLayerArr);
    ~MultiLayerPerceptron();
    void feedforward(Matrix& inputs) const;
    void backpropagate(const std::vector<double>& inputs, const std::vector<double>& outputs, double learningRate) const;
    /**
     * Return reference to generated outputs after applying the activation function on them.
     * @return Reference to activated outputs.
     */
    const Matrix& getOutputs() const;
    const Matrix& getRawOutputs() const;
    void print(std::ostream& stream) const;
    void recover(std::istream& stream) const;
    void setOutputActivationFunction(DoubleFunction function);
    const Layer& getLayer(int index) const;
};

#endif //AIENGINE_MLP_H
