#include <iostream>
#include "../common/common.h"
#include "5.4.h"
using namespace std;

int main() {
    cout << "Please, enter array size: ";
    int n;
    cin >> n;
    cout << endl;

    int *ar = createArray<int>(n);
    fillArrayRand(ar, n);
    //fillArrayKeyboard(ar, n);
    showArray(ar, n);
    int &max = refMaxFib(ar, n);
    max = 0;
    showArray(ar, n);

    deleteArray(ar);
    return 0;
}