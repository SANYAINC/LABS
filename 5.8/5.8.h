#pragma once
#include <cstring>

template <class T>
void merge(T *array, int left, int split, int right) {
    int indexFirst = left;          //Индекс для первой части
    int indexSecond = split + 1;    //Индекс для второй части

    T *buf = new T[right - left + 1]; //Буфер на размер двух частей
    int indexBuf = 0;

    //Пока мы не вышли за границы своей части
    while (indexFirst <= split and indexSecond <= right) {
        //Записываем меньший элемент в буфер
        if (array[indexFirst] < array[indexSecond]) {
            buf[indexBuf++] = array[indexFirst++];
        } else {
            buf[indexBuf++] = array[indexSecond++];
        }
    }

    //Если в частях остались элементы, записываем их в буфер
    while (indexFirst <= split) {
        buf[indexBuf++] = array[indexFirst++];
    }
    while (indexSecond <= right) {
        buf[indexBuf++] = array[indexSecond++];
    }

    //Записываем буфер в массив
    for (indexBuf = 0; indexBuf < right - left + 1; ++indexBuf) {
        array[left + indexBuf] = buf[indexBuf];
    }

    delete [] buf;
}

template <class T>
void mergeSort(T *array, int right, int left = 0) {
    int split;
    if (left < right) {
        split = (left + right) / 2; //Разделитель

        mergeSort(array, split, left); //Разбиваем левую часть
        mergeSort(array, right, split + 1); //Разбиваем правую часть

        merge(array, left, split, right); //Сливаем левую и правую часть
    }
}
void mergeSort(char **strings, int wordsAmount) {
    int len;
    for (int i = 0; i < wordsAmount; ++i) {
        len = strlen(strings[i]);
        mergeSort(strings[i], len - 1); //Вызов для каждого слова
    }
}
