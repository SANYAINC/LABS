#pragma once
#include <iostream>
#include <ctime>

using namespace std;

namespace arrays {
    template <class T> //Создание массива
    T *create(int size) {
        T *array = new T[size];
        for (int i = 0; i < size; ++i) {
            array[i] = static_cast<T>(0);
        }
        return array;
    }

    template <class T> //Освобождение памяти
    void free(T *array) {
        delete [] array;
        cout << "\nMEMORY FREED\n\n";
    }

    template <class T> //Вывести массив
    void show(T *array, int size) {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << ' ';
        }
        cout << endl;
    }
    template <class T>
    void show(T *array, int size, int start) {
        for (int i = start; i < size; ++i) {
            cout << array[i] << ' ';
        }
        cout << endl;
    }

    template <class T> //Заполнить массив случайными числами
    void fillRnd(T *array, int size, int max = 100, int shift = 50) {
        srand(time(nullptr));
        for (int i = 0; i < size; ++i) {
            array[i] = static_cast<T>(rand() % max + shift);
        }
    }
    template <class T> //Заполнить массив с клавиатуры
    void fillKbd(T *array, int size) {
        T buff;
        cout << "Please, enter " << size << " values: ";
        for (int i = 0; i < size; ++i) {
            cin >> buff;
            array[i] = static_cast<T>(buff);
        }
        cout << endl;
    }
    template <class T> //Заполнить по возрастанию
    void fillAsc(T *array, int size) {
        for (int i = 0; i < size; ++i) {
            array[i] = static_cast<T>(i);
        }
    }
    template <class T> //Заполнить по убыванию
    void fillDsc(T *array, int size) {
        for (int i = 0; i < size; ++i) {
            array[i] = static_cast<T>(size - i - 1);
        }
    }

    template <class T>
    int find(T *array, T element, int size) {
        for (int i = 0; i < size; ++i) {
            if (array[i] == element) {
                return i;
            }
        }
        return -1;
    }
    template <class T>
    int find(T *array, T element, int size, int start) {
        for (int i = start; i < size; ++i) {
            if (array[i] == element) {
                return i;
            }
        }
        return -1;
    }
}

namespace matrix {
    template <class T>
    T **create(int row, int col) {
        T **matrix = new T*[row];
        for (int i = 0; i < row; ++i) {
            matrix[i] = new T[col];
        }
        return matrix;
    }

    template <class T>
    void free(T **matrix, int row) {
        for (int i = 0; i < row; ++i) {
            delete [] matrix[i];
        }
        delete [] matrix;
        cout << "\nMEMORY FREED\n\n";
    }

    template <class T>
    void show(T **matrix, int row, int col) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }
}

namespace words {
    void showWords(char **words, int wordsAmount) {
        for (int i = 0; i < wordsAmount; ++i) {
            cout << words[i] << endl;
        }
    }
}

namespace sorts {
    template <class T>
    void quickSort(T *array, int right, int left = 0) {
        int leftPtr = left;
        int rightPtr = right;
        int basis = array[(leftPtr + rightPtr) / 2];
        while (leftPtr <= rightPtr) {
            while (array[leftPtr] < basis) {
                leftPtr++;
            }
            while (array[rightPtr] > basis) {
                rightPtr--;
            }
            if (leftPtr <= rightPtr) {
                swap(array[leftPtr], array[rightPtr]);
                leftPtr++;
                rightPtr--;
            }
        }
        if (left < rightPtr) {
            quickSort(array, rightPtr, left);
        }
        if (right > leftPtr) {
            quickSort(array, right, leftPtr);
        }
    }
}
