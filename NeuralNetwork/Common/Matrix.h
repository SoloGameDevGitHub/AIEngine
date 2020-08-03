#ifndef NEURALNETWORK_MATRIX_H
#define NEURALNETWORK_MATRIX_H
#include <ctime>
#include <iostream>
#include <math.h>
#include <cmath>
#include <cassert>
#include <vector>
#include <memory>

typedef float (*FloatFunction)(float);

class Matrix
{
private:
    std::vector<float> _values;
    int _rows;
    int _columns;

public:
    Matrix(int rows, int columns);
    float get(int row, int column) const;
    void set(int row, int column, float value);
    int getRows() const;
    int getColumns() const;
    void print(std::ostream& stream);
    void print(std::ostream& stream, int decimalPlace) const;
    static void applyFunction(FloatFunction function, const Matrix& source, Matrix&  target);
    void applyFunction(FloatFunction function);
    static std::shared_ptr<Matrix> multiply(const Matrix& left, const Matrix& right);
    static void multiply(const Matrix& left, const Matrix& right, Matrix& target);
    static void multiply(Matrix& target, float scalar);
    static void add(Matrix& target, float value);
};
#endif //NEURALNETWORK_MATRIX_H
