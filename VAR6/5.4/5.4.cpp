#include "5.4.h"

int isInArray(int num, const int *array, int size) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == num) {
            return i;
        }
    }
    return -1;
}

int &refMaxFib(int *array, int size) {
    //Поиск максимального значения массива и его индекса
    int maxIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }

    int fibCur = 1;
    int fibPrev = 1;

    int maxFibIndex = -1;    //Индекс максимального Ф
    int curFibIndex = 0;    //Индекс текущего Ф

    //Пока текущее число Ф меньше максимального в массиве
    while (fibCur <= array[maxIndex]) {
        curFibIndex = isInArray(fibCur, array, size); //Индекс текущего числа Ф в массиве, либо -1
        //Если найдено число Ф болше максимального, сохраняем
        if (curFibIndex != -1) {
            maxFibIndex = curFibIndex;
        }
        //Переход к следующемму числу Ф
        fibCur = fibCur + fibPrev;
        fibPrev = fibCur - fibPrev;
    }
    if (maxFibIndex == -1) {
        return array[maxIndex];
    } else {
        return array[maxFibIndex];
    }
}