#include <math.h>

namespace BitMath
{
    int reverseBits(const int value, int maxBits)
    {
        int reversedBits = 0;
        maxBits = (maxBits % 2 == 0) ? maxBits : maxBits - 1;
        int halfBits = (int) floor(maxBits / 2);
        for (int bit = 0; bit < halfBits; bit++)
        {
            int transposeDifference = (maxBits - (bit * 2) - 1);
            
            int rBit = value & (1 << bit);
            int lBit = rBit << transposeDifference;
            reversedBits |= lBit;
            
            lBit = value & (1 << (maxBits - 1 - bit));
            rBit = lBit >> transposeDifference;
            reversedBits |= rBit;
        }
        return reversedBits;
    }
}
