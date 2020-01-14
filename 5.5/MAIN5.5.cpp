#include <iostream>
#include "5.5.h"
#include "../common/common.h"
using namespace std;

int main() {
    //Указатели на функции
    double (*f1)(char, double) = &function;
    double (*f2)(char, double, double) = &function;

    cout << "----------------------------------------------------------------------\n";
    solveNewton(f1);
    cout << "----------------------------------------------------------------------\n";
    solveHalfDividing(f1);
    cout << "----------------------------------------------------------------------\n";
    solveNewton(f2);
    cout << "----------------------------------------------------------------------\n";
    solveHalfDividing(f2);
    cout << "----------------------------------------------------------------------\n";
    return 0;

}
