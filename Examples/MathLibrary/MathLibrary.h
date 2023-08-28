// MathLibrary.h - Contains declarations of math functions
#pragma once

#include "ApiExports.h"

MATHLIBRARY_API class MathFacade {
public:
    static int Sum(int lhs, int rhs);
    static int GetOne();
};

extern "C" {
    MATHLIBRARY_API int Sum(int lhs, int rhs);
    MATHLIBRARY_API int GetOne();
}
