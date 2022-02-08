#pragma once

#include <cmath>
#include <vector>

namespace NeuralNetwork
{
    namespace Activation
    {
        double sigmoid(const double&);
        void sigmoid(std::vector<double>&);

        double sign(const double&);
        void sign(std::vector<double>&);

        double threshold(const double&);
        void threshold(std::vector<double>&);
        void setThreshold(const double&&);

        enum class EActivationFunctionType
        {
            None,
            Sigmoid,
            Sign,
            Threshold,
        };

        void Apply(const EActivationFunctionType& activationFunctionType, double& value);
        void Apply(const EActivationFunctionType& activationFunctionType, std::vector<double>& vector);
    }
}
