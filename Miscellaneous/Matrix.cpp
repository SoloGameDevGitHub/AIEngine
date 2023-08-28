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

double Matrix::get(const int row, const int column) const
{
    int index = row * _columns + column;
    assert(index < (_rows * _columns));
    double value = _values[index];
    return value;
}

void Matrix::set(const int row, const int column, const double value)
{
    assert((row >= 0 && row < _rows) && (column >= 0 && column < _columns));
    const int index = row * _columns + column;
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

void Matrix::print(std::ostream& stream) const
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
            double value = get(r, c);
            double truncatedValue = floor(value * decimalFactor) / decimalFactor;
            stream << "[" << truncatedValue << "] ";
        }
        stream << std::endl;
    }
}

//STATIC FUNCTIONS
std::unique_ptr<Matrix> Matrix::multiply(const Matrix &left, const Matrix &right)
{
    std::unique_ptr<Matrix> result = std::make_unique<Matrix>(left.getRows(),right.getColumns());
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
            double sum = 0.0;
            for(int leftColumn = 0; leftColumn < left.getColumns(); ++leftColumn)
            {
                sum += left.get(row, leftColumn) * right.get(leftColumn, column);
            }
            target.set(row, column, sum);
        }
    }
}

void Matrix::multiply(Matrix& target, const double scalar)
{
    for (int r = 0; r < target.getRows(); ++r)
    {
        for (int c = 0; c < target.getColumns(); ++c)
        {
            double value = target.get(r,c) * scalar;
            target.set(r,c,value);
        }
    }
}

void Matrix::add(Matrix& target, const double value)
{
    for (int r = 0; r < target.getRows(); ++r)
    {
        for (int c = 0; c < target.getColumns(); ++c)
        {
            double sum = target.get(r, c) + value;
            target.set(r, c, sum);
        }
    }
}

std::unique_ptr<Matrix> Matrix::fromVectorRows(const std::vector<double>& vector)
{
    int size = vector.size();
    std::unique_ptr<Matrix> matrix = std::make_unique<Matrix>(size, 1);
    for (int i = 0; i < size; ++i) {
        const double number = vector[i];
        matrix->set(i, 0, number);
    }
    return matrix;
}

std::unique_ptr<Matrix> Matrix::fromVectorColumns(const std::vector<double>& vector)
{
    int size = vector.size();
    std::unique_ptr<Matrix> matrix = std::make_unique<Matrix>(1, size);
    for (int i = 0; i < size; ++i) {
        const double number = vector[i];
        matrix->set(0, i, number);
    }
    return matrix;
}

void Matrix::copy(const Matrix& source, Matrix& target)
{
    assert(source.getColumns() == target.getColumns());
    assert(source.getRows() == target.getRows());
    for (int r = 0; r < source.getRows(); ++r)
    {
        for (int c = 0; c < source.getRows(); ++c)
        {
            double value = source.get(r, c);
            target.set(r, c, value);
        }
    }
}
