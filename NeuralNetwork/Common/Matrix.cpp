#include "Matrix.h"

Matrix::Matrix(int rows, int columns) : _rows(rows),
                                        _columns(columns)
{
    assert(columns >= 1 && rows >= 1);
    _values.clear();
    int size = columns * rows;
    for(int i = 0; i < size; i++)
    {
        _values.push_back(0.0f);
    }
}

float Matrix::get(const int row, const int column) const
{
    int index = row * _columns + column;
    assert(index < (_rows * _columns));
    return _values[index];
}

void Matrix::set(const int row, const int column, const float value)
{
    assert((row >= 0 && row < _rows) && (column >= 0 && column < _columns));
    int index = row * _columns + column;
    _values[index] = value;
}

int Matrix::getRows() const
{
    return _rows;
}

int Matrix::getColumns() const
{
    return _columns;
}

void Matrix::print(std::ostream& stream)
{
    print(stream, 3);
}

void Matrix::print(std::ostream& stream, int decimalPlace) const
{
    int decimalFactor = static_cast<int>(pow(10, decimalPlace));
    assert(decimalFactor > 0);
    for (int r = 0; r < _rows; r++)
    {
        for (int c = 0; c < _columns; c++)
        {
            float value = get(r, c);
            float truncatedValue = floorf(value * decimalFactor) / decimalFactor;
            stream << "[" << truncatedValue << "] ";
        }
        stream << std::endl;
    }
}

//STATIC FUNCTIONS
std::shared_ptr<Matrix> Matrix::multiply(const Matrix &left, const Matrix &right)
{
    std::shared_ptr<Matrix> result = std::make_shared<Matrix>(left.getRows(),right.getColumns());
    multiply(left, right, *result);
    return result;
}

void Matrix::multiply(const Matrix& left, const Matrix& right, Matrix& target)
{
    assert(left.getColumns() == right.getRows());
    for(int row = 0; row < target.getRows(); ++row)
    {
        for(int column = 0; column < target.getColumns(); ++column)
        {
            float sum = 0.0;
            for(int leftColumn = 0; leftColumn < left.getColumns(); ++leftColumn)
            {
                sum += left.get(row, leftColumn) * right.get(leftColumn, column);
            }
            target.set(row, column, sum);
        }
    }
}

void Matrix::multiply(Matrix& target, const float scalar)
{
    for (int r = 0; r < target.getRows(); ++r)
    {
        for (int c = 0; c < target.getColumns(); ++c)
        {
            float value = target.get(r,c) * scalar;
            target.set(r,c,value);
        }
    }
}

void Matrix::add(Matrix& target, const float value)
{
    for (int r = 0; r < target.getRows(); ++r)
    {
        for (int c = 0; c < target.getColumns(); ++c)
        {
            float sum = target.get(r, c) + value;
            target.set(r, c, sum);
        }
    }
}

void Matrix::applyFunction(FloatFunction function, const Matrix& source, Matrix&  target)
{
    assert(function);
    assert(&source);
    assert(&target);
    assert(source.getRows() == target.getRows());
    assert(source.getColumns() == target.getColumns());
    for (int r = 0; r < source.getRows(); ++r)
    {
        for (int c = 0; c < source.getColumns(); ++c)
        {
            float newValue = function(source.get(r,c));
            target.set(r,c,newValue);
        }
    }
}

void Matrix::applyFunction(FloatFunction function)
{
    Matrix& matrix = *this;
    Matrix::applyFunction(function, matrix, matrix);
}
