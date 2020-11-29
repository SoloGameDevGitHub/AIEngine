#include "ActivationFunctions.h"

double _zeroOrOneThreshold = 0.5;

namespace neuralnetwork
{
    namespace activation
    {
        double sigmoid(double value)
        {
            double result = 1.0 / (1.0 + std::exp(-value));
            return result;
        }

        void sigmoid(std::vector<double> &source)
        {
            for (int i = 0; i < source.size(); ++i)
            {
                source[i] = sigmoid(source[i]);
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

        void threshold(std::vector<double> &source)
        {
            for (int i = 0; i < source.size(); ++i)
            {
                source[i] = threshold(source[i]);
            }
        }

        void setThreshold(double threshold)
        {
            _zeroOrOneThreshold = threshold;
        }
    }
}
