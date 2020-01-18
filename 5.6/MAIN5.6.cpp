#include "5.6.h"

int main() {
    //Указатель на функцию
    double (*f1)(double, double, double) = &function;

    solveIntegralMidRectangles(f1);

    return 0;
}