#include "ActivationFunctions.h"

double _zeroOrOneThreshold = 0.5;

double sigmoid(double value)
{
    double result = 1.0 / (1.0 + std::exp(value * -1.0));
    return result;
    //double k = std::exp(value);
    //return k / (1.0 + k);
}

double sign(double value)
{
    double result = value > 0.0 ? 1.0 : -1.0;
    return result;
}

double zeroOrOne(double value)
{
    return value >= _zeroOrOneThreshold ? 1.0 : 0.0;
}

double noActivation(double value)
{
    return value;
}

void setZeroOrOneThreshold(double threshold)
{
    _zeroOrOneThreshold = threshold;
}
