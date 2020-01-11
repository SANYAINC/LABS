#include <iostream>
#include <ctime>

using namespace std;

#ifndef LABSGIT_COMMON_H
#define LABSGIT_COMMON_H


template <class T>
T* createArray(int size) {

    ///Creates pointer (array)

    T *array = new T[size];
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<T>(0);
    }
    return array;
}

template <class T>
void removeArray(T *array) {

    ///Frees memory

    delete [] array;
    cout << "\nMEMORY FREED\n";
}

template <class T>
void showArray(T *array, int size) {

    ///Shows array on the screen

    for (int i = 0; i < size; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

template <class T>
void fillRandArr(T *array, int size) {

    ///Fills array with random values

    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<T>(rand()%30+30);
    }
}

template <class T>
void fillArray(T *array, int size) {

    ///Fills array via keyboard

    T buff;
    cout << "Please, enter " << size << " values: ";
    for (int i = 0; i < size; ++i) {
        cin >> buff;
        array[i] = buff;
    }
    cout << endl;
}


#endif //LABSGIT_COMMON_H
