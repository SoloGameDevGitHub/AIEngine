#include "Matrix.h"

Matrix::Matrix(const int rows, const int columns)
{
    assert(columns >= 1 && rows >= 1);
    _rows = rows;
    _columns = columns;
    _values = (float*) calloc(columns * rows, sizeof(float));
}

Matrix::~Matrix()
{
    delete [] _values;
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

void Matrix::print(std::ostream& stream, int decimalPlace)
{
    int decimalFactor = pow(10, decimalPlace);
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

Matrix* Matrix::clone()
{
    Matrix* result = new Matrix(getRows(), getColumns());
    for (int r = 0; r < getRows(); ++r)
    {
        for (int c = 0; c < getColumns(); ++c)
        {
            float value = get(r,c);
            result->set(r,c,value);
        }
    }
    return result;
}

//STATIC FUNCTIONS
Matrix* Matrix::multiply(const Matrix& left, const Matrix& right)
{
    Matrix* result = new Matrix(left.getRows(),right.getColumns());
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

void Matrix::applyFunction(FloatFunction function)
{
    for (int r = 0; r < getRows(); ++r)
    {
        for (int c = 0; c < getColumns(); ++c)
        {
            float newValue = function(get(r,c));
            set(r,c,newValue);
        }
    }
}
