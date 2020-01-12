#include <iostream>
#include "5.5.h"
#include "../common/common.h"
using namespace std;

int main() {
    double (*f1)(char, double) = &function1;
    solveNewton(f1);
    return 0;
}
