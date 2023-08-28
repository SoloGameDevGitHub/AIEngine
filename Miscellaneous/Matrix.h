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
    double Get(int row, int column) const;
    void Set(int row, int column, double value);
    int GetRows() const;
    int GetColumns() const;
    void Print(std::ostream& stream) const;
    void Print(std::ostream& stream, int decimalPlace) const;

    static std::unique_ptr<Matrix> Multiply(const Matrix& left, const Matrix& right);
    static void Multiply(const Matrix& left, const Matrix& right, Matrix& target);
    static void Multiply(Matrix& target, double scalar);
    static void Add(Matrix& target, double value);
    static std::unique_ptr<Matrix> FromVectorRows(const std::vector<double>& vector);
    static std::unique_ptr<Matrix> FromVectorColumns(const std::vector<double>& vector);
    static void Copy(const Matrix& source, Matrix& target);
};
