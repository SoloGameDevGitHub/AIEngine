#ifndef NEURALNETWORK_MATRIX_H
#define NEURALNETWORK_MATRIX_H
#include <ctime>
#include <iostream>
#include <cmath>
#include <cassert>

typedef float (*FloatFunction)(float);

class Matrix
{
private:
    float* _values;
    int _rows;
    int _columns;

public:
    Matrix(const int rows, const int columns);
    ~Matrix();
    float get(const int row, const int column) const;
    void set(const int row, const int column, const float value);
    int getRows() const;
    int getColumns() const;
    void print(std::ostream& stream);
    void print(std::ostream& stream, int decimalPlace);
    Matrix* clone();
    void applyFunction(FloatFunction function);

    static Matrix* multiply(const Matrix& left, const Matrix& right);
    static void multiply(const Matrix& left, const Matrix& right, Matrix& target);
    static void multiply(Matrix& target, const float scalar);
    static void add(Matrix& target, const float value);
};
#endif //NEURALNETWORK_MATRIX_H
