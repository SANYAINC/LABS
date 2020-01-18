#include <iostream>
#include <ctime>

#pragma once

using namespace std;

template <class T> //Создание указателя на size элементовT
T *createArray(int size) {
    T *array = new T[size];
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<T>(0);
    }
    return array;
}

template <class T> //Освобождение памяти
void deleteArray(T *array) {
    delete [] array;
    cout << "\nMEMORY FREED\n";
}

template <class T> //Вывести массив
void showArray(T *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

template <class T> //Заполнить массив случайными числами
void fillArrRand(T *array, int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<T>(rand()%30+30);
    }
}

template <class T> //Заполнить массив с клавиатуры
void fillArrayKeyboard(T *array, int size) {
    T buff;
    cout << "Please, enter " << size << " values: ";
    for (int i = 0; i < size; ++i) {
        cin >> buff;
        array[i] = buff;
    }
    cout << endl;
}