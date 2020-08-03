#ifndef AIENGINE_ACTIVATIONFUNCTIONS_H
#define AIENGINE_ACTIVATIONFUNCTIONS_H
#include <cmath>

float sigmoid(float value);
float sign(float value);
float zeroOrOne(float value);
float noActivation(float value);
void setZeroOrOneThreshold(float threshold);

#endif //AIENGINE_ACTIVATIONFUNCTIONS_H
