#include "ActivationFunctions.h"

double activationfunction::sigmoid(double value)
{
    double result = 1.0 / (1.0 + std::exp(-value));
    return result;
}

void activationfunction::sigmoid(std::vector<double>& source)
{
    for (int i = 0; i < source.size(); ++i)
    {
        source[i] = sigmoid(source[i]);
    }
}

double activationfunction::sign(double value)
{
    if (value > 0.0)
    {
        return 1.0;
    }
    return -1.0;
}

double activationfunction::threshold(double value)
{
    if (value >= _zeroOrOneThreshold)
    {
        return 1.0;
    }
    return 0.0;
}

void activationfunction::setThreshold(double threshold)
{
    _zeroOrOneThreshold = threshold;
}
