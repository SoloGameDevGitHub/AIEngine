#include "ActivationFunctions.h"

namespace NeuralNetwork
{
    namespace Activation
    {
        double thresholdValue = 0.5;

        double Sigmoid(const double& value)
        {
            double result = 1.0 / (1.0 + std::exp(-value));
            return result;
        }

        void Sigmoid(std::vector<double>& vector)
        {
            for (double& i : vector)
            {
                i = Sigmoid(i);
            }
        }

        double Sign(const double& value)
        {
            if (value > 0.0)
            {
                return 1.0;
            }
            return -1.0;
        }

        void Sign(std::vector<double>& vector)
        {
            for (double& i : vector)
            {
                i = Sign(i);
            }
        }

        double Threshold(const double& value)
        {
            if (value >= thresholdValue)
            {
                return 1.0;
            }
            return 0.0;
        }

        void Threshold(std::vector<double>& vector)
        {
            for (double& i : vector)
            {
                i = Threshold(i);
            }
        }

        void SetThreshold(const double&& threshold)
        {
            thresholdValue = threshold;
        }

        void Apply(const EActivationFunctionType& activationFunctionType, double& value)
        {
            switch(activationFunctionType)
            {
                case EActivationFunctionType::None: break;

                case EActivationFunctionType::Sigmoid:
                    value = Sigmoid(value);
                    break;

                case EActivationFunctionType::Sign:
                    value = Sign(value);
                    break;

                case EActivationFunctionType::Threshold:
                    value = Threshold(value);
                    break;
            }
        }

        void Apply(const EActivationFunctionType &activationFunctionType, std::vector<double> &vector)
        {
            switch(activationFunctionType)
            {
                case EActivationFunctionType::None: break;

                case EActivationFunctionType::Sigmoid:
                    Sigmoid(vector);
                    break;

                case EActivationFunctionType::Sign:
                    Sign(vector);
                    break;

                case EActivationFunctionType::Threshold:
                    Threshold(vector);
                    break;
            }
        }
    }
}
