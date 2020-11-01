#ifndef AIENGINE_ACTIVATIONFUNCTIONS_H
#define AIENGINE_ACTIVATIONFUNCTIONS_H
#include <cmath>

double sigmoid(double value);
double sign(double value);
double zeroOrOne(double value);
double noActivation(double value);
void setZeroOrOneThreshold(double threshold);

#endif //AIENGINE_ACTIVATIONFUNCTIONS_H
