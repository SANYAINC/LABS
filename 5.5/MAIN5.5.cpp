#include <iostream>
#include "5.5.h"
#include "../common/common.h"
using namespace std;

int main() {
    //Указатели на функции
    double (*f1)(char, double) = &function;
    double (*f2)(char, double, double) = &function;

    cout << "----------------------------------------------------------------------\n";

    printTableHeader(0);

    solveNewton(f1);
    solveHalfDividing(f1);
    solveChords(f1);

    cout << "\n----------------------------------------------------------------------\n";

    printTableHeader(1);

    solveNewton(f2);
    cout << "\n";
    solveHalfDividing(f2);
    cout << "\n";
    solveChords(f2);

    cout << "\n----------------------------------------------------------------------\n";
    return 0;

}
