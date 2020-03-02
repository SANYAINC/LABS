#include <iostream>
#include "5.7.h"
#include "../../common/common.h"

using namespace std;

template <class T>
void test(char sortType, T *array, int size) {
    int comps = 0;
    int movings = 0;
    cout << "-------------------------------------------------------------------------\n";
    if (sortType == 'Q') {
        cout << "QUICK SORT\n";
        arrays::show(array, size);
        quickSort(array, comps, movings, size - 1);
        cout << endl;
        arrays::show(array, size);
        cout << endl;
        cout << "Comparisons number: " << comps << endl;
        cout << "Movings number: "<< movings << "\n";
        cout << "-------------------------------------------------------------------------\n";
    }
    if (sortType == 'B') {
        cout << "BUBBLE SORT\n";
        arrays::show(array, size);
        bubbleSort(array, comps, movings, size);
        cout << endl;
        arrays::show(array, size);
        cout << endl;
        cout << "Comparisons number: " << comps << endl;
        cout << "Movings number: "<< movings << "\n";
        cout << "-------------------------------------------------------------------------\n";
    }
    if (sortType == 'I') {
        cout << "INSERTION SORT\n";
        arrays::show(array, size);
        insertionSort(array, comps, movings, size);
        cout << endl;
        arrays::show(array, size);
        cout << endl;
        cout << "Comparisons number: " << comps << endl;
        cout << "Movings number: "<< movings << "\n";
        cout << "-------------------------------------------------------------------------\n";
    }
    if (sortType == '2') {
        cout << "BINARY INSERTION SORT\n";
        arrays::show(array, size);
        binInsertionSort(array, comps, movings, size);
        cout << endl;
        arrays::show(array, size);
        cout << endl;
        cout << "Comparisons number: " << comps << endl;
        cout << "Movings number: "<< movings << "\n";
        cout << "-------------------------------------------------------------------------\n";
    }
    if (sortType == 'S') {
        cout << "SELECTION SORT\n";
        arrays::show(array, size);
        selectionSort(array, comps, movings, size);
        cout << endl;
        arrays::show(array, size);
        cout << endl;
        cout << "Comparisons number: " << comps << endl;
        cout << "Movings number: "<< movings << "\n";
        cout << "-------------------------------------------------------------------------\n";
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
    auto *ar1R = arrays::create<int>(n);
    auto *ar1A = arrays::create<int>(n);
    auto *ar1D = arrays::create<int>(n);

    auto *ar2R = arrays::create<double>(n);
    auto *ar2A = arrays::create<double>(n);
    auto *ar2D = arrays::create<double>(n);

    arrays::fillRnd(ar1R, n);
    arrays::fillAsc(ar1A, n);
    arrays::fillDsc(ar1D, n);

    arrays::fillRnd(ar2R, n);
    arrays::fillAsc(ar2A, n);
    arrays::fillDsc(ar2D, n);

    //Q - быстрая, B - пузырьком, I - вставками, 2 - бинарными вставкавми, S - выбором
    test('Q', ar1R, n);
    test('B', ar2R, n);
    test('Q', ar1A, n);
    test('B', ar2A, n);
    test('Q', ar1D, n);
    test('B', ar2D, n);

    //Очистка памяти
    arrays::free(ar1R);
    arrays::free(ar2R);
    arrays::free(ar1A);
    arrays::free(ar2A);
    arrays::free(ar1D);
    arrays::free(ar2D);
    return 0;
}
