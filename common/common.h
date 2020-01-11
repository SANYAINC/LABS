#include "iostream"
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
void showArray(T *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl;
}



#endif //LABSGIT_COMMON_H
