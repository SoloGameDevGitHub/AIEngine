#pragma once
#include <ctime>
#include <iostream>
#include <math.h>
#include <cmath>
#include <cassert>
#include <vector>
#include <memory>

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

    static std::unique_ptr<Matrix> multiply(const Matrix& left, const Matrix& right);
    static void multiply(const Matrix& left, const Matrix& right, Matrix& target);
    static void multiply(Matrix& target, double scalar);
    static void add(Matrix& target, double value);
    static std::unique_ptr<Matrix> fromVectorRows(const std::vector<double>& vector);
    static std::unique_ptr<Matrix> fromVectorColumns(const std::vector<double>& vector);
    static void copy(const Matrix& source, Matrix& target);
};
