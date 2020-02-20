#include <iostream>
#include "7.2.h"
#include "../common/common.h"

using namespace std;


int main() {
    squareMatrix2D A(5);
    A.fillAsIdentity();
    A.show();
    A.raise(10);
    A.show();

    squareMatrix2D A2(2);
    A2.fillRandom();
    A2.show();
    A2.raise(2);
    A2.show();

    squareMatrix1D B(5);
    B.fillAsIdentity();
    B.show();
    B.raise(3);
    B.show();

    squareMatrix2D B2(2);
    B2.fillRandom();
    B2.show();
    B2.raise(2);
    B2.show();



    return 0;
}