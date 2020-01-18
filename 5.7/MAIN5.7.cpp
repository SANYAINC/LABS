#include <iostream>
#include "5.7.h"
#include "../common/common.h"

using namespace std;

template <class T>
void test(char sortType, T *array, int size) {
    int comps = 0;
    int movings = 0;
    cout << "-------------------------------------------------------------------------\n";
    if (sortType == 'Q') {
        cout << "QUICK SORT\n";
        showArray(array, size);
        quickSort(array, comps, movings, size - 1);
        cout << endl;
        showArray(array, size);
        cout << endl;
        cout << "Comparisons number: " << comps << endl;
        cout << "Movings number: "<< movings << "\n\n";
        cout << "-------------------------------------------------------------------------\n";
        comps = 0;
        movings = 0;
    }
    if (sortType == 'B') {
        cout << "BUBBLE SORT\n";
        showArray(array, size);
        bubbleSort(array, comps, movings, size);
        cout << endl;
        showArray(array, size);
        cout << endl;
        cout << "Comparisons number: " << comps << endl;
        cout << "Movings number: "<< movings << "\n\n";
        cout << "-------------------------------------------------------------------------\n";
        comps = 0;
        movings = 0;
    }
}

int main() {
    cout << "Please, enter N: ";
    int n;
    cin >> n;
    cout << endl;

    int *ar1R = createArray<int>(n);
    int *ar2R = createArray<int>(n);
    int *ar1A = createArray<int>(n);
    int *ar2A = createArray<int>(n);
    int *ar1D = createArray<int>(n);
    int *ar2D = createArray<int>(n);

    fillArrayRand(ar1R, n);
    fillArrayRand(ar2R, n);
    fillArrayAsc(ar1A, n);
    fillArrayAsc(ar2A, n);
    fillArrayDsc(ar1D, n);
    fillArrayDsc(ar2D, n);

    test('Q', ar1R, n);
    test('B', ar2R, n);
    test('Q', ar1A, n);
    test('B', ar2A, n);
    test('Q', ar1D, n);
    test('B', ar2D, n);

    deleteArray(ar1R);
    deleteArray(ar2R);
    deleteArray(ar1A);
    deleteArray(ar2A);
    deleteArray(ar1D);
    deleteArray(ar2D);
    return 0;
}
