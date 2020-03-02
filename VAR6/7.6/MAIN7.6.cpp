#include <iostream>
#include "7.6.h"

using namespace std;

int main() {
    list l1;
    int array[6] = {5, 7, 8, 11, 9, 1};

    l1.pushBack(array, 6);
    l1.pushBack(5);
    l1.pushBack(7);
    cout << l1.calculateProd();
    return 0;
}