#pragma once

#include <cstring>
#include "../../common/common.h"

#define WORD_LEN 1000

void merge(char **words, int left, int split, int right) {
    int indexFirst = left;          //Индекс для первой части
    int indexSecond = split + 1;    //Индекс для второй части

    char **buf = new char*[right - left + 1]; //Буфер на размер двух частей
    for (int i = 0; i < right - left + 1; ++i) {
        buf[i] = new char[WORD_LEN];
    }
    int indexBuf = 0;

    //Пока мы не вышли за границы своей части
    while (indexFirst <= split and indexSecond <= right) {
        //Записываем меньший элемент в буфер
        if (strcmp(words[indexFirst], words[indexSecond]) < 0) {
            strcpy(buf[indexBuf++], words[indexFirst++]);
        } else {
            strcpy(buf[indexBuf++], words[indexSecond++]);
        }
    }

    //Если в частях остались элементы, записываем их в буфер
    while (indexFirst <= split) {
        strcpy(buf[indexBuf++], words[indexFirst++]);
    }
    while (indexSecond <= right) {
        strcpy(buf[indexBuf++], words[indexSecond++]);
    }

    //Записываем буфер в массив
    for (indexBuf = 0; indexBuf < right - left + 1; ++indexBuf) {
        strcpy(words[left + indexBuf], buf[indexBuf]);
    }

    for (int i = 0; i < right - left + 1; ++i) {
        delete [] buf[i];
    }
    delete [] buf;
}
void mergeSort(char **words, int right, int left = 0) {
    int split;
    if (left < right) {
        split = (left + right) / 2; //Разделитель

        mergeSort(words, split, left); //Разбиваем левую часть
        mergeSort(words, right, split + 1); //Разбиваем правую часть
        merge(words, left, split, right); //Сливаем левую и правую часть
    }
}

template<class T>
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

template<class T>
void mergeSort(T *array, int right, int left = 0) {
    int split;
    if (left < right) {
        split = (left + right) / 2; //Разделитель

        mergeSort(array, split, left); //Разбиваем левую часть
        mergeSort(array, right, split + 1); //Разбиваем правую часть

        merge(array, left, split, right); //Сливаем левую и правую часть
    }
}


