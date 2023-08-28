#include "Matrix.h"

Matrix::Matrix(int rows, int columns) : _rows(rows),
                                        _columns(columns)
{
    assert(columns >= 1 && rows >= 1);
    int size = columns * rows;
    _values = std::vector<double>(size);
}

Matrix::Matrix(const Matrix& source)
{
    _values = source._values;
    _rows = source._rows;
    _columns = source._columns;
}

double Matrix::Get(const int row, const int column) const
{
    int index = row * _columns + column;
    assert(index < (_rows * _columns));
    double value = _values[index];
    return value;
}

void Matrix::Set(const int row, const int column, const double value)
{
    assert((row >= 0 && row < _rows) && (column >= 0 && column < _columns));
    const int index = row * _columns + column;
    _values[index] = value;
}

int Matrix::GetRows() const
{
    return _rows;
}

int Matrix::GetColumns() const
{
    return _columns;
}

void Matrix::Print(std::ostream& stream) const
{
    Print(stream, 3);
}

void Matrix::Print(std::ostream& stream, int decimalPlace) const
{
    int decimalFactor = static_cast<int>(pow(10, decimalPlace));
    assert(decimalFactor > 0);
    for (int r = 0; r < _rows; r++)
    {
        for (int c = 0; c < _columns; c++)
        {
            double value = Get(r, c);
            double truncatedValue = floor(value * decimalFactor) / decimalFactor;
            stream << "[" << truncatedValue << "] ";
        }
        stream << std::endl;
    }
}

//STATIC FUNCTIONS
std::unique_ptr<Matrix> Matrix::Multiply(const Matrix &left, const Matrix &right)
{
    std::unique_ptr<Matrix> result = std::make_unique<Matrix>(left.GetRows(),right.GetColumns());
    Multiply(left, right, *result);
    return result;
}

void Matrix::Multiply(const Matrix& left, const Matrix& right, Matrix& target)
{
    assert(left.GetColumns() == right.GetRows());
    for(int row = 0; row < target.GetRows(); ++row)
    {
        for(int column = 0; column < target.GetColumns(); ++column)
        {
            double sum = 0.0;
            for(int leftColumn = 0; leftColumn < left.GetColumns(); ++leftColumn)
            {
                sum += left.Get(row, leftColumn) * right.Get(leftColumn, column);
            }
            target.Set(row, column, sum);
        }
    }
}

void Matrix::Multiply(Matrix& target, const double scalar)
{
    for (int r = 0; r < target.GetRows(); ++r)
    {
        for (int c = 0; c < target.GetColumns(); ++c)
        {
            double value = target.Get(r,c) * scalar;
            target.Set(r,c,value);
        }
    }
}

void Matrix::Add(Matrix& target, const double value)
{
    for (int r = 0; r < target.GetRows(); ++r)
    {
        for (int c = 0; c < target.GetColumns(); ++c)
        {
            double sum = target.Get(r, c) + value;
            target.Set(r, c, sum);
        }
    }
}

std::unique_ptr<Matrix> Matrix::FromVectorRows(const std::vector<double>& vector)
{
    int size = vector.size();
    std::unique_ptr<Matrix> matrix = std::make_unique<Matrix>(size, 1);
    for (int i = 0; i < size; ++i) {
        const double number = vector[i];
        matrix->Set(i, 0, number);
    }
    return matrix;
}

std::unique_ptr<Matrix> Matrix::FromVectorColumns(const std::vector<double>& vector)
{
    int size = vector.size();
    std::unique_ptr<Matrix> matrix = std::make_unique<Matrix>(1, size);
    for (int i = 0; i < size; ++i) {
        const double number = vector[i];
        matrix->Set(0, i, number);
    }
    return matrix;
}

void Matrix::Copy(const Matrix& source, Matrix& target)
{
    assert(source.GetColumns() == target.GetColumns());
    assert(source.GetRows() == target.GetRows());
    for (int r = 0; r < source.GetRows(); ++r)
    {
        for (int c = 0; c < source.GetRows(); ++c)
        {
            double value = source.Get(r, c);
            target.Set(r, c, value);
        }
    }
}
