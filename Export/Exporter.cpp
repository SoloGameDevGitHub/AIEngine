#ifdef _EXPORT_DLL_
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

extern "C"
{
API int sum(int lhs, int rhs)
{
    return lhs + rhs;
}

API int getOne()
{
    return 1;
}
}
