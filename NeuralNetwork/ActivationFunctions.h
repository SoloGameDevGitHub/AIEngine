#pragma once

#include <cmath>
#include <vector>

namespace neuralnetwork
{
    namespace activation
    {
        typedef double (*function)(double);
        typedef void (*vector_function)(std::vector<double>&);
        double sigmoid(double value);
        void sigmoid(std::vector<double>& source);
        double sign(double value);
        double threshold(double value);
        void threshold(std::vector<double>& source);
        void setThreshold(double threshold);
    }
}
