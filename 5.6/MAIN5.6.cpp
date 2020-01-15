#include "5.6.h"

int main() {
    double (*f1)(double, double, double) = &function;
    solveIntegral(f1);
    return 0;
}