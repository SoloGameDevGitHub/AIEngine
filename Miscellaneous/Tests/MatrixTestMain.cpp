#include "../Matrix.h"
#include <memory>

using namespace std;

int main()
{
    cout << "Matrix * Matrix" << endl;
    auto left = make_unique<Matrix>(1,3);
    left->set(0,0,1);
    left->set(0,1,2);
    left->set(0,2,3);
    auto right = make_unique<Matrix>(3,1);
    right->set(0,0,4);
    right->set(1,0,5);
    right->set(2,0,6);
    auto dotProduct = Matrix::multiply(*left, *right);
    dotProduct->print(cout);

    cout << endl;
    left = make_unique<Matrix>(3,1);
    left->set(0,0,4);
    left->set(1,0,5);
    left->set(2,0,6);
    right = make_unique<Matrix>(1,3);
    right->set(0,0,1);
    right->set(0,1,2);
    right->set(0,2,3);
    dotProduct = Matrix::multiply(*left, *right);
    dotProduct->print(cout);

    cout << endl;
    left = make_unique<Matrix>(1,3);
    left->set(0,0,3);
    left->set(0,1,4);
    left->set(0,2,2);
    right = make_unique<Matrix>(3,4);
    right->set(0,0,13);
    right->set(0,1,9);
    right->set(0,2,7);
    right->set(0,3,15);
    right->set(1,0,8);
    right->set(1,1,7);
    right->set(1,2,4);
    right->set(1,3,6);
    right->set(2,0,6);
    right->set(2,1,4);
    right->set(2,2,0);
    right->set(2,3,3);
    dotProduct = Matrix::multiply(*left, *right);
    dotProduct->print(cout);

    cout << endl;
    left = make_unique<Matrix>(3,3);
    left->set(0,0,0.9);
    left->set(0,1,0.3);
    left->set(0,2,0.4);
    left->set(1,0,0.2);
    left->set(1,1,0.8);
    left->set(1,2,0.2);
    left->set(2,0,0.1);
    left->set(2,1,0.5);
    left->set(2,2,0.6);
    right = make_unique<Matrix>(3, 1);
    right->set(0,0,0.9);
    right->set(1,0,0.1);
    right->set(2,0,0.8);
    dotProduct = Matrix::multiply(*left, *right);
    dotProduct->print(cout);

    cout << endl << "Matrix * Scalar" << endl;
    Matrix::multiply(*dotProduct, 2.0);
    dotProduct->print(cout);

    return 0;
}
