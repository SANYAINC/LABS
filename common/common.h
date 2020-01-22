#pragma once
#include <iostream>
#include <ctime>
using namespace std;

namespace arrays {
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
}

namespace matrix {
    template <class T>
    T **createMatrix(int row, int col) {
        T **matrix = new T*[row];
        for (int i = 0; i < row; ++i) {
            matrix[i] = new T[col];
        }
        return matrix;
    }

    template <class T>
    void deleteMatrix(T **matrix, int row) {
        for (int i = 0; i < row; ++i) {
            delete [] matrix[i];
        }
        delete [] matrix;
        cout << "MEMORY FREED\n";
    }

    template <class T>
    void showMatrix(T **matrix, int row, int col) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }
    void showWords(char **words, int wordsAmount) {
        for (int i = 0; i < wordsAmount; ++i) {
            cout << words[i] << endl;
        }
    }
}



