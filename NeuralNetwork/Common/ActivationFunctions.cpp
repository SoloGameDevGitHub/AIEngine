#include "ActivationFunctions.h"

namespace NeuralNetwork
{
    namespace activation
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
    }
}
