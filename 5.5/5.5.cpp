#include <iostream>
#include "5.5.h"
#include "../common/common.h"
using namespace std;

int main() {
    double (*f1)(char, double) = &function;
    double (*f2)(char, double, double) = &function;

    cout << "----------------------------------------------------------------------\n";
    solveNewton(f1);
    cout << "----------------------------------------------------------------------\n";
    solveNewton(f2);
    cout << "----------------------------------------------------------------------\n";
    return 0;

}
