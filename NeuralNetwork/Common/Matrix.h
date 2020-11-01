#ifndef NEURALNETWORK_MATRIX_H
#define NEURALNETWORK_MATRIX_H
#include <ctime>
#include <iostream>
#include <math.h>
#include <cmath>
#include <cassert>
#include <vector>
#include <memory>

typedef double (*DoubleFunction)(double);

class Matrix
{
private:
    std::vector<double> _values;
    int _rows;
    int _columns;

public:
    Matrix(int rows, int columns);
    Matrix(const Matrix& source);
    double get(int row, int column) const;
    void set(int row, int column, double value);
    int getRows() const;
    int getColumns() const;
    void print(std::ostream& stream) const;
    void print(std::ostream& stream, int decimalPlace) const;
    static void applyFunction(DoubleFunction function, const Matrix& source, Matrix&  target);
    void applyFunction(DoubleFunction function);
    static std::unique_ptr<Matrix> multiply(const Matrix& left, const Matrix& right);
    static void multiply(const Matrix& left, const Matrix& right, Matrix& target);
    static void multiply(Matrix& target, double scalar);
    static void add(Matrix& target, double value);
    static std::unique_ptr<Matrix> fromVectorRows(const std::vector<double>& vector);
};
#endif //NEURALNETWORK_MATRIX_H
