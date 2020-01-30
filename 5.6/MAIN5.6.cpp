#include <iostream>
#include "5.6.h"

using namespace std;

int main() {
    //Указатель на функцию
    double (*f1)(double, double, double) = &function;

    solveIntegralMR(f1); //Средние прямоугольники

    return 0;
}