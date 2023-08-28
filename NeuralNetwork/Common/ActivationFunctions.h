#pragma once

#include <cmath>
#include <vector>

namespace NeuralNetwork
{
    namespace Activation
    {
        double Sigmoid(const double&);
        void Sigmoid(std::vector<double>&);

        double Sign(const double&);
        void Sign(std::vector<double>&);

        double Threshold(const double&);
        void Threshold(std::vector<double>&);
        void SetThreshold(const double&&);

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
