#include <iostream>
#include "5.6.h"

using namespace std;

int main() {
    //Указатель на функцию
    double (*f1)(double, double, double) = &function;

    solveIntegralMR(f1);
    cout << "------------------------------------------------------------\n";
    solveIntegralT(f1);
    cout << "------------------------------------------------------------\n";
    solveIntegralS(f1);

    return 0;
}