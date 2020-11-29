#pragma once

#include <cmath>
#include <vector>

namespace activationfunction
{
    namespace {
        double _zeroOrOneThreshold = 0.5;
    }

    typedef double (*function)(double);

    double sigmoid(double value);
    void sigmoid(std::vector<double>& source);
    double sign(double value);
    double threshold(double value);
    void setThreshold(double threshold);
}
