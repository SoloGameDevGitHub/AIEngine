#ifndef AIENGINE_LAYER_H
#define AIENGINE_LAYER_H

#include <memory>
#include "../Perceptron/Perceptron.h"

class Layer
{
private:
    std::vector<Perceptron*> _perceptrons;
    std::unique_ptr<Matrix> _outputs;
    const int _inputsLength;

public:
    Layer(int perceptronsLength, int inputsLength);
    ~Layer();
    void print(std::ostream& stream);
    void recover(std::istream& stream);
    void feedforward(const Matrix& inputs);
    Matrix& getOutputs() const;
};

#endif //AIENGINE_LAYER_H
