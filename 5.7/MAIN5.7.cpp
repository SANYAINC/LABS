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
        //showArray(array, size);
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
        //showArray(array, size);
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
        //showArray(array, size);
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
        //showArray(array, size);
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
    if (sortType == 'S') {
        cout << "SELECTION SORT\n";
        //showArray(array, size);
        selectionSort(array, comps, movings, size);
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
    //Цифра - номер массива,
    //R - заполнение случайными, A - по возрастанию, D - по убыванию
    int *ar1R = createArray<int>(n);
    float *ar2R = createArray<float>(n);
    double *ar3R = createArray<double>(n);
    char *ar4R = createArray<char>(n);
    int *ar5R = createArray<int>(n);
    int *ar1A = createArray<int>(n);
    float *ar2A = createArray<float>(n);
    double *ar3A = createArray<double>(n);
    char *ar4A= createArray<char>(n);
    int *ar5A = createArray<int>(n);
    int *ar1D = createArray<int>(n);
    float *ar2D = createArray<float>(n);
    double *ar3D = createArray<double>(n);
    char *ar4D = createArray<char>(n);
    int *ar5D = createArray<int>(n);

    //Заполнение 4х массивов 4мя вариантами
    fillArrayRand(ar1R, n);
    fillArrayRand(ar2R, n);
    fillArrayRand(ar3R, n);
    fillArrayRand(ar4R, n);
    fillArrayRand(ar5R, n);
    fillArrayAsc(ar1A, n);
    fillArrayAsc(ar2A, n);
    fillArrayAsc(ar3A, n);
    fillArrayAsc(ar4A, n);
    fillArrayAsc(ar5A, n);
    fillArrayDsc(ar1D, n);
    fillArrayDsc(ar2D, n);
    fillArrayDsc(ar3D, n);
    fillArrayDsc(ar4D, n);
    fillArrayDsc(ar5D, n);

    //Q - быстрая, B - пузырьком, I - вставками, 2 - бинарными вставкавми, S - выбором
    test('Q', ar1R, n);
    test('B', ar2R, n);
    test('I', ar3R, n);
    test('2', ar4R, n);
    test('S', ar5R, n);
    cout << "\n\n\n";
    test('Q', ar1A, n);
    test('B', ar2A, n);
    test('I', ar3A, n);
    test('2', ar4A, n);
    test('S', ar5A, n);
    cout << "\n\n\n";
    test('Q', ar1D, n);
    test('B', ar2D, n);
    test('I', ar3D, n);
    test('2', ar4D, n);
    test('S', ar5D, n);

    deleteArray(ar1R);
    deleteArray(ar2R);
    deleteArray(ar3R);
    deleteArray(ar4R);
    deleteArray(ar5R);
    deleteArray(ar1A);
    deleteArray(ar2A);
    deleteArray(ar3A);
    deleteArray(ar4A);
    deleteArray(ar5A);
    deleteArray(ar1D);
    deleteArray(ar2D);
    deleteArray(ar3D);
    deleteArray(ar4D);
    deleteArray(ar5D);
    return 0;
}
