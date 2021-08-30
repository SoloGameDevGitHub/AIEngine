#include "ActivationFunctions.h"

namespace neuralnetwork
{
    namespace activation
    {
        static double _zeroOrOneThreshold = 0.5;

        double sigmoid(double value)
        {
            double result = 1.0 / (1.0 + std::exp(-value));
            return result;
        }

        void sigmoid(std::vector<double>& source)
        {
            for (double& i : source)
            {
                i = sigmoid(i);
            }
        }

        double sign(double value)
        {
            if (value > 0.0)
            {
                return 1.0;
            }
            return -1.0;
        }

        double threshold(double value)
        {
            if (value >= _zeroOrOneThreshold)
            {
                return 1.0;
            }
            return 0.0;
        }

        void threshold(std::vector<double>& source)
        {
            for (double& i : source)
            {
                i = threshold(i);
            }
        }

        void setThreshold(double threshold)
        {
            _zeroOrOneThreshold = threshold;
        }
    }
}
