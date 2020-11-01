#ifndef AIENGINE_LAYER_H
#define AIENGINE_LAYER_H

#include <memory>
#include "../Perceptron/Perceptron.h"

class Layer
{
private:
    std::vector<std::unique_ptr<Perceptron>> _perceptrons;
    std::unique_ptr<Matrix> _outputs;
    const int _inputsLength;

public:
    Layer(int perceptronsLength, int inputsLength);
    ~Layer();
    void print(std::ostream& stream) const;
    void recover(std::istream& stream) const;
    void feedforward(const Matrix& inputs);
    const Perceptron& getPerceptron(int index) const;
    const Matrix& getOutputs() const;
};

#endif //AIENGINE_LAYER_H
