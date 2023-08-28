#include "ActivationFunctions.h"

namespace NeuralNetwork
{
    namespace Activation
    {
        double thresholdValue = 0.5;

        double sigmoid(const double& value)
        {
            double result = 1.0 / (1.0 + std::exp(-value));
            return result;
        }

        void sigmoid(std::vector<double>& vector)
        {
            for (double& i : vector)
            {
                i = sigmoid(i);
            }
        }

        double sign(const double& value)
        {
            if (value > 0.0)
            {
                return 1.0;
            }
            return -1.0;
        }

        void sign(std::vector<double>& vector)
        {
            for (double& i : vector)
            {
                i = sign(i);
            }
        }

        double threshold(const double& value)
        {
            if (value >= thresholdValue)
            {
                return 1.0;
            }
            return 0.0;
        }

        void threshold(std::vector<double>& vector)
        {
            for (double& i : vector)
            {
                i = threshold(i);
            }
        }

        void setThreshold(const double&& threshold)
        {
            thresholdValue = threshold;
        }

        void Apply(const EActivationFunctionType& activationFunctionType, double& value)
        {
            switch(activationFunctionType)
            {
                case EActivationFunctionType::None: break;

                case EActivationFunctionType::Sigmoid:
                    value = sigmoid(value);
                    break;

                case EActivationFunctionType::Sign:
                    value = sign(value);
                    break;

                case EActivationFunctionType::Threshold:
                    value = threshold(value);
                    break;
            }
        }

        void Apply(const EActivationFunctionType &activationFunctionType, std::vector<double> &vector)
        {
            switch(activationFunctionType)
            {
                case EActivationFunctionType::None: break;

                case EActivationFunctionType::Sigmoid:
                    sigmoid(vector);
                    break;

                case EActivationFunctionType::Sign:
                    sign(vector);
                    break;

                case EActivationFunctionType::Threshold:
                    threshold(vector);
                    break;
            }
        }
    }
}
