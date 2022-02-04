#pragma once

#include <cmath>
#include <vector>

namespace NeuralNetwork
{
    namespace activation
    {
        typedef double (*function)(const double&);
        typedef void (*vector_function)(std::vector<double>&);
        double sigmoid(const double&);
        void sigmoid(std::vector<double>&);
        double sign(const double&);
        double threshold(const double&);
        void threshold(std::vector<double>&);
        void setThreshold(const double&&);
    }
}
