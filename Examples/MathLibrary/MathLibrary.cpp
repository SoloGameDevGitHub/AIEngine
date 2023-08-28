#include "MathLibrary.h"

int Sum(int lhs, int rhs)
{
    return lhs + rhs;
}

int GetOne()
{
    return 1;
}

int MathFacade::Sum(int lhs, int rhs)
{
    return ::Sum(lhs, rhs);
}

int MathFacade::GetOne()
{
    return ::GetOne();
}
