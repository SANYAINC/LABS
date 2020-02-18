#include <iostream>
#include "7.3.h"

using namespace std;

int main() {
    date b1(14, 9, 2001);
    b1.print();
    student sanya("Alexander", "Sibirtsev", "Vyacheslavovich", b1, 1, 6.7);
    sanya.print();
    return 0;
}

