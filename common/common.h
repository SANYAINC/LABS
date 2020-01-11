#include <iostream>
#include <ctime>

using namespace std;

#ifndef LABSGIT_COMMON_H
#define LABSGIT_COMMON_H


template <class T>
T* createArray(int size) {
    T *array = new T[size];
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<T>(0);
    }
    return array;
}

template <class T>
void removeArray(T *array) {
    delete [] array;
    cout << "\nMEMORY FREED\n";
}

template <class T>
void showArray(T *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

template <class T>
void fillRandArr(T *array, int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<T>(rand()%30+30);
    }
}



#endif //LABSGIT_COMMON_H
