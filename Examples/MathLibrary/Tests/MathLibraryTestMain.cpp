#include <iostream>

#include "../MathLibrary.h"

using namespace std;

int main()
{
    cout << "MathFacade::Sum" << endl;
    cout << " (1, 3): " << MathFacade::Sum(1, 3) << " " << endl;

    cout << "::Sum" << endl;
    cout << " (1, 3): " << Sum(1, 3) << " " << endl;

    cout << "MathFacade::GetOne" << endl;
    cout << " (): " << MathFacade::GetOne() << " " << endl;

    cout << "::GetOne" << endl;
    cout << " (): " << GetOne() << " " << endl;

    return 0;
}
