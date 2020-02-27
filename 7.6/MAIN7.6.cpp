#include <iostream>
#include "7.6.h"

using namespace std;

int main() {
    list l1;
    int array[8] = {5, 7, 8, 11, 9, 0, 3, 2};
    l1.pushBack(array, 8);
    cout << l1.calculateProd();
    return 0;
}