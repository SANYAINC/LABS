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
        cout << "Movings number: "<< movings << "\n";
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
        cout << "Movings number: "<< movings << "\n";
        cout << "-------------------------------------------------------------------------\n";
        comps = 0;
        movings = 0;
    }
    if (sortType == 'I') {
        cout << "INSERTION SORT\n";
        showArray(array, size);
        insertionSort(array, comps, movings, size);
        cout << endl;
        showArray(array, size);
        cout << endl;
        cout << "Comparisons number: " << comps << endl;
        cout << "Movings number: "<< movings << "\n";
        cout << "-------------------------------------------------------------------------\n";
        comps = 0;
        movings = 0;
    }
    if (sortType == '2') {
        cout << "BINARY INSERTION SORT\n";
        showArray(array, size);
        binInsertionSort(array, comps, movings, size);
        cout << endl;
        showArray(array, size);
        cout << endl;
        cout << "Comparisons number: " << comps << endl;
        cout << "Movings number: "<< movings << "\n";
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

    //Создание массивов для тестов
    int *ar1R = createArray<int>(n);
    int *ar2R = createArray<int>(n);
    int *ar3R = createArray<int>(n);
    int *ar4R = createArray<int>(n);
    int *ar1A = createArray<int>(n);
    int *ar2A = createArray<int>(n);
    int *ar3A = createArray<int>(n);
    int *ar4A= createArray<int>(n);
    int *ar1D = createArray<int>(n);
    int *ar2D = createArray<int>(n);
    int *ar3D = createArray<int>(n);
    int *ar4D = createArray<int>(n);

    //Заполнение 4х массивов 4мя вариантами
    fillArrayRand(ar1R, n);
    fillArrayRand(ar2R, n);
    fillArrayRand(ar3R, n);
    fillArrayRand(ar4R, n);
    fillArrayAsc(ar1A, n);
    fillArrayAsc(ar2A, n);
    fillArrayAsc(ar3A, n);
    fillArrayAsc(ar4A, n);
    fillArrayDsc(ar1D, n);
    fillArrayDsc(ar2D, n);
    fillArrayDsc(ar3D, n);
    fillArrayDsc(ar4D, n);

    //Q - быстрая, B - пузырьком, I - вставками, 2 - бинарными вставкавми
    test('Q', ar1R, n);
    test('B', ar2R, n);
    test('I', ar3R, n);
    test('2', ar4R, n);
    cout << "\n\n\n";
    test('Q', ar1A, n);
    test('B', ar2A, n);
    test('I', ar3A, n);
    test('2', ar4A, n);
    cout << "\n\n\n";
    test('Q', ar1D, n);
    test('B', ar2D, n);
    test('I', ar3D, n);
    test('2', ar4D, n);

    deleteArray(ar1R);
    deleteArray(ar2R);
    deleteArray(ar3R);
    deleteArray(ar4R);
    deleteArray(ar1A);
    deleteArray(ar2A);
    deleteArray(ar3A);
    deleteArray(ar4A);
    deleteArray(ar1D);
    deleteArray(ar2D);
    deleteArray(ar3D);
    deleteArray(ar4D);
    return 0;
}