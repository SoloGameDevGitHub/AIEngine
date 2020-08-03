#ifndef AIENGINE_ACTIVATIONFUNCTIONS_H
#define AIENGINE_ACTIVATIONFUNCTIONS_H

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

#endif //AIENGINE_ACTIVATIONFUNCTIONS_H
