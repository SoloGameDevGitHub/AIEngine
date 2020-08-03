#include "ActivationFunctions.h"

float _zeroOrOneThreshold = 0.5f;

float sigmoid(float value)
{
    float result = 1.0f / (1.0f + std::exp(value * -1.0f));
    return result;
}

float sign(float value)
{
    float result = value > 0.0f ? 1.0f : -1.0f;
    return result;
}

float zeroOrOne(float value)
{
    return value >= _zeroOrOneThreshold ? 1.0f : 0.0f;
}

float noActivation(float value)
{
    return value;
}

void setZeroOrOneThreshold(float threshold)
{
    _zeroOrOneThreshold = threshold;
}
