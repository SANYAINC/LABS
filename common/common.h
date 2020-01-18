#pragma once

#include <iostream>
#include <ctime>

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
    cout << "MEMORY FREED\n";
}

template <class T> //Вывести массив
void showArray(T *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

template <class T> //Заполнить массив случайными числами
void fillArrayRand(T *array, int size, int max = 30, int shift = 30) {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<T>(rand() % max + shift);
    }
}

template <class T> //Заполнить массив с клавиатуры
void fillArrayKbrd(T *array, int size) {
    T buff;
    cout << "Please, enter " << size << " values: ";
    for (int i = 0; i < size; ++i) {
        cin >> buff;
        array[i] = static_cast<T>(buff);
    }
    cout << endl;
}

template <class T> //Заполнить по возрастанию
void fillArrayAsc(T *array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<T>(i);
    }
}

template <class T> //Заполнить по убыванию
void fillArrayDsc(T *array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<T>(size - i - 1);
    }
}
