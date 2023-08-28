#include "../Matrix.h"
#include <memory>

using namespace std;

int main()
{
    cout << "Matrix * Matrix" << endl;
    auto left = make_unique<Matrix>(1,3);
    left->Set(0,0,1);
    left->Set(0,1,2);
    left->Set(0,2,3);
    auto right = make_unique<Matrix>(3,1);
    right->Set(0,0,4);
    right->Set(1,0,5);
    right->Set(2,0,6);
    auto dotProduct = Matrix::Multiply(*left, *right);
    dotProduct->Print(cout);

    cout << endl;
    left = make_unique<Matrix>(3,1);
    left->Set(0,0,4);
    left->Set(1,0,5);
    left->Set(2,0,6);
    right = make_unique<Matrix>(1,3);
    right->Set(0,0,1);
    right->Set(0,1,2);
    right->Set(0,2,3);
    dotProduct = Matrix::Multiply(*left, *right);
    dotProduct->Print(cout);

    cout << endl;
    left = make_unique<Matrix>(1,3);
    left->Set(0,0,3);
    left->Set(0,1,4);
    left->Set(0,2,2);
    right = make_unique<Matrix>(3,4);
    right->Set(0,0,13);
    right->Set(0,1,9);
    right->Set(0,2,7);
    right->Set(0,3,15);
    right->Set(1,0,8);
    right->Set(1,1,7);
    right->Set(1,2,4);
    right->Set(1,3,6);
    right->Set(2,0,6);
    right->Set(2,1,4);
    right->Set(2,2,0);
    right->Set(2,3,3);
    dotProduct = Matrix::Multiply(*left, *right);
    dotProduct->Print(cout);

    cout << endl;
    left = make_unique<Matrix>(3,3);
    left->Set(0,0,0.9);
    left->Set(0,1,0.3);
    left->Set(0,2,0.4);
    left->Set(1,0,0.2);
    left->Set(1,1,0.8);
    left->Set(1,2,0.2);
    left->Set(2,0,0.1);
    left->Set(2,1,0.5);
    left->Set(2,2,0.6);
    right = make_unique<Matrix>(3, 1);
    right->Set(0,0,0.9);
    right->Set(1,0,0.1);
    right->Set(2,0,0.8);
    dotProduct = Matrix::Multiply(*left, *right);
    dotProduct->Print(cout);

    cout << endl << "Matrix * Scalar" << endl;
    Matrix::Multiply(*dotProduct, 2.0);
    dotProduct->Print(cout);

    return 0;
}
