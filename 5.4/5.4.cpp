#include <iostream>
#include "../common/common.h"
#include "5.4.h"
using namespace std;

int main() {
    int *ar = createArray<int>(5);
    ar[0] = -5;
    ar[1] = 1;
    ar[2] = 150;
    ar[3] = 0;
    ar[4] = 55;
    cout << refMaxFib(ar, 5);

    return 0;
}